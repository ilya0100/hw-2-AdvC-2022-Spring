#include "max_seq.h"


size_t find_max_incr_sequence(Array *arr, const size_t n) {
    if (!arr) {
        return 0;
    }

    size_t part_length = (arr->size + n - 1) / n;

    Array **indexes = calloc(n, sizeof(Array *));
    for (size_t i = 0; i < n; ++i) {
        indexes[i] = create_array(0);
        if (!indexes[i]) {
            for (size_t j = 0; j < n; ++j) {
                free_array(indexes[j]);
            }
            free(indexes);
            return 0;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        size_t begin = part_length * i;
        size_t end = part_length * (i + 1);
        find_local_incr_sequence(arr, begin, end, indexes[i]);
    }

    size_t max_length = 0;
    if (add_elem(indexes[n - 1], arr->size)) {
        for (size_t i = 0; i < n; ++i) {
            free_array(indexes[i]);
        }
        free(indexes);
        return 0;
    }

    size_t prev = indexes[0]->data[0];
    for (size_t i = 0; i < n; ++i) {
        if (indexes[i]->data) {
            for (size_t j = 0; j < indexes[i]->size; ++j) {
                if (i == 0 && j == 0) {
                    ++j;
                }
                if (indexes[i]->data[j] - prev > max_length) {
                    max_length = indexes[i]->data[j] - prev;
                }
                prev = indexes[i]->data[j];
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        free_array(indexes[i]);
    }
    free(indexes);
    return max_length;
}

void *find_local_incr_sequence(Array *arr, size_t begin, size_t end, Array *indexes) {
    if (!arr || !indexes) {
        return NULL;
    }

    if (begin == 0 || arr->data[begin - 1] >= arr->data[begin]) {
        if (add_elem(indexes, begin)) {
            return NULL;
        }
    }

    for (size_t i = begin + 1; i < end && i < arr->size; ++i) {
        if (arr->data[i - 1] >= arr->data[i]) {
            if (add_elem(indexes, i)) {
                return NULL;
            }
        }
    }

    return NULL;
}
