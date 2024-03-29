cmake_minimum_required(VERSION 3.14)
project(test_find_max_incr_sequence)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})


find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${ARRAY_INCLUDE_DIRS} ${FIND_MAX_INCR_SEQUENCE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${ARRAY_LIBRARIES} ${FIND_MAX_INCR_SEQUENCE_SINGLE_LIBRARIES} ${FIND_MAX_INCR_SEQUENCE_MULTI_LIBRARIES} GTest::GTest gtest_main Threads::Threads)