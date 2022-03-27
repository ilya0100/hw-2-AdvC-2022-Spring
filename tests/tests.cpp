#include "utils.hpp"


TEST(GoodCase, ArrrayCreation) {
    Array arr = {0};
    int test_arr[] = {1, 2, 3, 4};

    for (size_t i = 0; i < 4; ++i) {
        ASSERT_EQ(0, add_elem(&arr, test_arr[i]));
    }

    for (size_t i = 0; i < arr.size; ++i) {
        ASSERT_EQ(arr.data[i], test_arr[i]);
    }

    free_array(&arr);
}
