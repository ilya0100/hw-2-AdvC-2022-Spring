#include "array.h"

#define MIN_SIZE 120

void free_array(Array *arr) {
    if (!arr) {
        return;
    }
    if (!arr->data) {
        return;
    }
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int resize_array(Array *arr) {
    if (!arr) {
        return -1;
    }

    size_t new_capacity = arr->capacity >= MIN_SIZE ? arr->capacity * 2 : MIN_SIZE;
    int *temp = realloc(arr->data, new_capacity * sizeof(int));
    if (!temp) {
        return -1;
    }

    arr->data = temp;
    arr->capacity = new_capacity;
    return 0;
}

int add_elem(Array *arr, const int x) {
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

void print_array(const Array arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        printf("%d ", arr.data[i]);
    }
}
