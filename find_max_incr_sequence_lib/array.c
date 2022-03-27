#include "array.h"

#define MIN_SIZE 120

Array *create_array(size_t n) {
    Array *new_array = calloc(1, sizeof(Array));
    if (!new_array) {
        return NULL;
    }
    if (n) {
        new_array->data = calloc(n , sizeof(size_t));
        new_array->capacity = n;

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

int add_elem(Array *arr, const size_t x) {
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

void print_array(const Array *arr) {
    if (!arr) {
        return;
    }
    for (size_t i = 0; i < arr->size; ++i) {
        printf("%zu ", arr->data[i]);
    }
}
