#!/usr/bin/env sh
mkdir build || true
cd build
cmake ..
export CTEST_OUTPUT_ON_FAILURE=1
make && make test
