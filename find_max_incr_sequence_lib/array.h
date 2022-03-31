#ifndef FIND_MAX_INCR_SEQUENCE_LIB_ARRAY_H_
#define FIND_MAX_INCR_SEQUENCE_LIB_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>


typedef struct {
    size_t *data;
    size_t size;
    size_t capacity;
} Array;

Array *create_array(size_t n);
void free_array(Array *arr);
int resize_array(Array *arr);
int push_back(Array *arr, const size_t x);

void print_array(const Array *arr);
void print_all_array_info(const Array *arr);

#endif  // FIND_MAX_INCR_SEQUENCE_LIB_ARRAY_H_
