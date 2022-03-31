#ifndef FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_H_
#define FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_H_

#include "array.h"
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>


size_t find_max_incr_sequence(Array *arr, const size_t n);
// void find_local_incr_sequence(Array *arr, size_t begin, size_t end, Array *indexes);
size_t find_local_incr_sequence(Array *arr, size_t begin, size_t end, size_t *data);

#endif  // FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_H_
