#include "array.h"

#define MIN_SIZE 120

Array *create_array(size_t n) {
    Array *new_array = calloc(1, sizeof(Array));
    if (!new_array) {
        return NULL;
    }
    if (n) {
        new_array->data = calloc(n, sizeof(size_t));
        new_array->capacity = n;
        new_array->size = n;

        if (!new_array->data) {
            free(new_array);
            return NULL;
        }
    }
    return new_array;
}

void free_array(Array *arr) {
    if (!arr) {
        return;
    }
    if (!arr->data) {
        return;
    }
    free(arr->data);
    free(arr);
}

Array *create_mmap_array(size_t size) {
    Array *new_array = create_array(0);
    if (!new_array) {
        return NULL;
    }

    new_array->data = mmap(NULL, sizeof(size_t) * size,
                           PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (new_array->data == MAP_FAILED) {
        free(new_array);
        return NULL;
    }
    new_array->size = size;
    new_array->capacity = size;

    return new_array;
}

void free_mmap_array(Array *arr) {
    if (!arr) {
        return;
    }

    if (arr->data != MAP_FAILED) {
        munmap(arr->data, arr->size);
    }
    free(arr);
}

int resize_array(Array *arr) {
    if (!arr) {
        return -1;
    }

    size_t new_capacity = arr->capacity >= MIN_SIZE ? arr->capacity * 2 : MIN_SIZE;
    size_t *temp = realloc(arr->data, new_capacity * sizeof(size_t));
    if (!temp) {
        return -1;
    }

    arr->data = temp;
    arr->capacity = new_capacity;
    return 0;
}

int push_back(Array *arr, const size_t x) {
    if (!arr) {
        return -1;
    }

    if (arr->size + 1 >= arr->capacity) {
        if (resize_array(arr)) {
            return -1;
        }
    }

    arr->data[arr->size] = x;
    ++arr->size;
    return 0;
}
