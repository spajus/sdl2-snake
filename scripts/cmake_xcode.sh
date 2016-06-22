#!/bin/sh
pushd .
rm -rf xcode/
mkdir -p xcode
cd xcode
cmake -G Xcode ../
popd
