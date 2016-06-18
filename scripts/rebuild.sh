#!/bin/sh
pushd .
rm -rf build/
mkdir -p build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
make && make install
popd
