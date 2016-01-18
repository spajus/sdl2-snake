#!/bin/sh
git submodule init
git submodule update

# GTest
cd deps/googletest/googletest/
mkdir -p build/
cd build
cmake ../ && make && sudo make install
cd ../../../../

# GMock
cd deps/googletest/googlemock/
mkdir -p build/
cd build
cmake ../ && make && sudo make install
cd ../../../../
