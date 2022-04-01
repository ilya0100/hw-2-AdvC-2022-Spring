#include "utils.h"

#define STRESS_TEST_ARRAY_SIZE 1000000000

TEST(ArrayBaseTests, ArrrayCreation) {
    Array *arr = create_array(0);
    ASSERT_NE(arr, nullptr);
    
    size_t test_arr[] = {1, 2, 3, 4};

    for (size_t i = 0; i < 4; ++i) {
        ASSERT_EQ(0, push_back(arr, test_arr[i]));
    }

    for (size_t i = 0; i < arr->size; ++i) {
        ASSERT_EQ(arr->data[i], test_arr[i]);
    }

    free_array(arr);
}

TEST(ArrayBaseTests, MMapArrayCreation) {
    Array *arr = create_mmap_array(5);
    ASSERT_NE(arr, nullptr);
    ASSERT_NE(arr->data, nullptr);

    for (size_t i = 0; i < 5; ++i) {
        arr->data[i] = i;
    }

    for (size_t i = 0; i < arr->size; ++i) {
        ASSERT_EQ(arr->data[i], i);
    }

    free_mmap_array(arr);
}

TEST(LogicTest, IncreaseArray) {
    const size_t max_length = 20;

    Array *arr = create_array(max_length);
    ASSERT_NE(arr, nullptr);

    for (size_t i = 0; i < arr->size; ++i) {
        arr->data[i] = i;
    }

    EXPECT_EQ(max_length, find_max_incr_sequence(arr));

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);
    size_t out_length = find_max_incr_sequence_multiproc(arr, num_cpu);
    if (out_length == 0) {
        free_array(arr);
        exit(0);
    }

    EXPECT_EQ(max_length, out_length);
    free_array(arr);
}

TEST(LogicTest, DecreaseArray) {
    Array *arr = create_array(40);
    ASSERT_NE(arr, nullptr);

    for (size_t i = 0; i < arr->size; ++i) {
        arr->data[i] = arr->size - i;
    }

    EXPECT_EQ(1, find_max_incr_sequence(arr));

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);
    size_t out_length = find_max_incr_sequence_multiproc(arr, num_cpu);
    if (out_length == 0) {
        free_array(arr);
        exit(0);
    }

    EXPECT_EQ(1, out_length);
    free_array(arr);
}

TEST(LogicTest, RandomArray) {
    Array *arr = gen_array(50, 0, 100);
    ASSERT_NE(arr, nullptr);

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);
    size_t out_length = find_max_incr_sequence_multiproc(arr, num_cpu);
    if (out_length == 0) {
        free_array(arr);
        exit(0);
    }

    EXPECT_EQ(find_max_incr_sequence(arr), out_length);
    free_array(arr);
}

TEST(StressTest, SingleProcess) {
    Array *arr = gen_array(STRESS_TEST_ARRAY_SIZE, 0, 100);
    ASSERT_NE(arr, nullptr);

    auto begin = std::chrono::high_resolution_clock::now();
    size_t out_length = find_max_incr_sequence(arr);
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_NE(out_length, 0);

    std::chrono::duration<float> time = end - begin;
    std::cout << "Single process time: " << time.count() << std::endl;

    free_array(arr);
}

TEST(StressTest, MultiProcess) {
    Array *arr = gen_array(STRESS_TEST_ARRAY_SIZE, 0, 100);
    ASSERT_NE(arr, nullptr);

    size_t num_cpu = sysconf(_SC_NPROCESSORS_ONLN);

    auto begin = std::chrono::high_resolution_clock::now();
    size_t out_length = find_max_incr_sequence_multiproc(arr, num_cpu);
    if (out_length == 0) {
        free_array(arr);
        exit(0);
    }
    auto end = std::chrono::high_resolution_clock::now();

    EXPECT_NE(out_length, 0);

    std::chrono::duration<float> time = end - begin;
    std::cout << "Multi process time: " << time.count() << std::endl;

    free_array(arr);
}
