cmake_minimum_required(VERSION 3.0.0)
project(max_increasing_sequence)

add_subdirectory(find_max_incr_sequence_lib)

message("FIND_MAX_INCR_SEQUENCE_INCLUDE_DIRS = ${FIND_MAX_INCR_SEQUENCE_INCLUDE_DIRS}")
message("FIND_MAX_INCR_SEQUENCE_LIBRARIES = ${FIND_MAX_INCR_SEQUENCE_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -ggdb3")

target_include_directories(${PROJECT_NAME} PUBLIC ${FIND_MAX_INCR_SEQUENCE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${FIND_MAX_INCR_SEQUENCE_LIBRARIES})

add_subdirectory(tests)