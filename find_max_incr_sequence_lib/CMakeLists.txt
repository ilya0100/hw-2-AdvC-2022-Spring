cmake_minimum_required(VERSION 3.14)
project(find_max_incr_sequence_lib)

add_subdirectory(array_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})


# Create single process library
set(SINGLE_PROC_LIBRARIES find_max_incr_sequence_single_lib)

add_library(${SINGLE_PROC_LIBRARIES} STATIC max_seq_singleproc.c)

target_include_directories(${SINGLE_PROC_LIBRARIES} PUBLIC ${ARRAY_INCLUDE_DIRS})
target_link_libraries(${SINGLE_PROC_LIBRARIES} PRIVATE ${ARRAY_LIBRARIES})

# Create multi process library
set(MULTI_PROC_LIBRARIES find_max_incr_sequence_multi_lib)

add_library(${MULTI_PROC_LIBRARIES} SHARED max_seq_multiproc.c)

target_include_directories(${MULTI_PROC_LIBRARIES} PUBLIC ${ARRAY_INCLUDE_DIRS})
target_link_libraries(${MULTI_PROC_LIBRARIES} PRIVATE ${ARRAY_LIBRARIES})


set(FIND_MAX_INCR_SEQUENCE_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

set(FIND_MAX_INCR_SEQUENCE_SINGLE_LIBRARIES ${SINGLE_PROC_LIBRARIES} PARENT_SCOPE)
set(FIND_MAX_INCR_SEQUENCE_MULTI_LIBRARIES ${MULTI_PROC_LIBRARIES} PARENT_SCOPE)

set(ARRAY_LIBRARIES ${ARRAY_LIBRARIES} PARENT_SCOPE)
set(ARRAY_INCLUDE_DIRS ${ARRAY_INCLUDE_DIRS} PARENT_SCOPE)