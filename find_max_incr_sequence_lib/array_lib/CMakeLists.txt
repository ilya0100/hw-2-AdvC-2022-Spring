cmake_minimum_required(VERSION 3.14)
project(array_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(ARRAY_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(ARRAY_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)