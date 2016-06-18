#!/bin/sh
pushd .
cd build
make && make install
popd
