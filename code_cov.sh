#!/usr/bin/env bash

cd build

lcov -t "tests/test_find_max_incr_sequence" -o coverage.info -c -d find_max_incr_sequence_lib/
genhtml -o report coverage.info