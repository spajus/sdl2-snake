#!/bin/sh
mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
make && ./RunTests
