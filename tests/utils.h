#ifndef TESTS_UTILS_H_
#define TESTS_UTILS_H_

#include <gtest/gtest.h>
#include <random>
#include <chrono>

extern "C" {
    #include "array.h"
    #include "max_seq_singleproc.h"
    #include "max_seq_multiproc.h"
}

size_t gen_value(size_t from, size_t to);
Array *gen_array(size_t size, size_t from, size_t to);

#endif  // TESTS_UTILS_H_
