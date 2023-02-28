#include "utils.h"


static std::random_device engine;


size_t gen_value(size_t from, size_t to) {
    return std::uniform_int_distribution<size_t>(from, to)(engine);
}

Array *gen_array(size_t size, size_t from, size_t to) {
    Array *new_array = create_array(size);
    if (!new_array) {
        return nullptr;
    }

    for (size_t i = 0; i < size; ++i) {
        new_array->data[i] = gen_value(from, to);
    }
    return new_array;
}
