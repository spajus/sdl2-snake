#!/bin/sh

cd deps/googletest/googletest/
mkdir -p build/
cd build
cmake ../ && make && sudo make install
cd ../../../../
pwd

mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
make && ./RunTests
