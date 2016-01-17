#!/bin/sh
pushd .
cd build
make && ./RunTests
popd
