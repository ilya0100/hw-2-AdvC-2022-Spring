#include "max_seq.h"


size_t find_max_incr_sequence(int *arr, size_t size, size_t *max_index) {
    if (!arr || !max_index) {
        return 0;
    }

    size_t length = 0;
    size_t max_length = 0;
    size_t index = 0;

    for (size_t i = 0; i < size; ++i) {
        ++length;
        if (i == size - 1 || arr[i] >= arr[i + 1]) {
            if (length >= max_length) {
                max_length = length;
                *max_index = index;
            }
            index = i + 1;
            length = 0;
        }
    }

    return max_length;
}
