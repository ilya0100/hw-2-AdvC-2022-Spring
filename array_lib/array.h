#ifndef ARRAY_LIB_ARRAY_H_
#define ARRAY_LIB_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Array;

void free_array(Array *arr);
int resize_array(Array *arr);
int add_elem(Array *arr, const int x);

void print_array(const Array arr);

#endif  // ARRAY_LIB_ARRAY_H_
