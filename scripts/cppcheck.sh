#!/bin/sh
# TODO: do it with cmake
cppcheck --enable=all --enable=style --inconclusive --std=c++11 -q --verbose -I include/ src/
