#pragma once

#include <gtest/gtest.h>

extern "C" {
    #include "max_seq_multiproc.h"
    #include "array.h"
}

bool arraycmp(const Array &l, const Array &r);
