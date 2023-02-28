#include "max_seq_singleproc.h"


size_t find_max_incr_sequence(Array *arr) {
    if (!arr) {
        return 0;
    }

    size_t length = 0;
    size_t max_length = 0;

    for (size_t i = 0; i < arr->size; ++i) {
        ++length;
        if (i == arr->size - 1 || arr->data[i] >= arr->data[i + 1]) {
            if (length >= max_length) {
                max_length = length;
            }
            length = 0;
        }
    }

    return max_length;
}
