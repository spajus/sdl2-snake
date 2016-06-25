#!/bin/sh
# TODO: do it with cmake
cppcheck --enable=all --std=c++11 -I include/ src/
