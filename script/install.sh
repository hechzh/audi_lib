#!/bin/sh
cd ..
mkdir build
cd build
cmake ..
make
cd ..
rm -rf build
