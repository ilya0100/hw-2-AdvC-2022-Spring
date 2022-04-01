#ifndef FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_MULTIPROC_H_
#define FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_MULTIPROC_H_

#include "array.h"
#include <unistd.h>
#include <sys/wait.h>


size_t find_max_incr_sequence_multiproc(Array *arr, size_t n);

#endif  // FIND_MAX_INCR_SEQUENCE_LIB_MAX_SEQ_MULTIPROC_H_
