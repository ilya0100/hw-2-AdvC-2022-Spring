#include "max_seq_multiproc.h"


static size_t merge_processes_data(Array *indexes, Array *lengths) {
    if (!indexes || !lengths) {
        return 0;
    }

    size_t max_length = 0;
    size_t prev_index = 0;

    for (size_t i = 1; i < indexes->size; ++i) {
        if (indexes->data[i] != 0) {
            if (i % 2 == 0 && indexes->data[i] - prev_index > max_length) {
                max_length = indexes->data[i] - prev_index;
            }
            prev_index = indexes->data[i];
        }
    }

    for (size_t i = 1; i < lengths->size; ++i) {
        if (lengths->data[i] > max_length) {
            max_length = lengths->data[i];
        }
    }

    return max_length;
}

static size_t find_local_incr_sequence(Array *arr, size_t begin, size_t end, size_t *data) {
    if (!arr || !data || begin >= arr->size) {
        return 0;
    }

    while (begin != 0 &&  begin < end - 1 && begin < arr->size - 1 &&
           arr->data[begin - 1] < arr->data[begin]) {
        ++begin;
    }
    if (begin == 0 || arr->data[begin - 1] >= arr->data[begin]) {
        data[0] = begin;
    }

    size_t max_length = 0;
    size_t prev_index = begin;

    for (size_t i = begin + 1; i < end && i < arr->size; ++i) {
        if (arr->data[i - 1] >= arr->data[i]) {
            if (i - prev_index > max_length) {
                max_length = i - prev_index;
            }
            prev_index = i;
        }
    }
    if (prev_index != begin) {
        data[1] = prev_index;
    }

    return max_length;
}

size_t find_max_incr_sequence(Array *arr, size_t n) {
    if (!arr) {
        return 0;
    }
    if (n > arr->size) {
        n = 1;
    }

    Array *indexes = create_mmap_array(2 * n + 1);
    if (!indexes) {
        return 0;
    }
    Array *lengths = create_mmap_array(n);
    if (!lengths) {
        free_mmap_array(indexes);
        return 0;
    }
    pid_t *pid = calloc(n, sizeof(pid_t));
    if (!pid) {
        free_mmap_array(indexes);
        free_mmap_array(lengths);
        return 0;
    }

    size_t part_length = (arr->size + n - 1) / n;
    for (size_t i = 0; i < n; ++i) {
        size_t begin = part_length * i;
        size_t end = part_length * (i + 1);

        pid[i] = fork();
        if (pid[i] == -1) {
            free_mmap_array(indexes);
            free_mmap_array(lengths);
            free(pid);
            return 0;
        }

        if (pid[i] == 0) {
            lengths->data[i] = find_local_incr_sequence(arr, begin, end, indexes->data + 2 * i);

            free_mmap_array(indexes);
            free_mmap_array(lengths);
            free(pid);

            exit(EXIT_SUCCESS);
        }
    }
    indexes->data[indexes->size - 1] = arr->size;

    int status;
    pid_t waited_pid;
    for (size_t i = 0; i < n; ++i) {
        waited_pid = wait(&status);

        if (waited_pid == -1) {
            free_mmap_array(indexes);
            free_mmap_array(lengths);
            free(pid);
            return 0;
        }
    }

    size_t max_length = merge_processes_data(indexes, lengths);

    free_mmap_array(indexes);
    free_mmap_array(lengths);
    free(pid);
    return max_length;
}
