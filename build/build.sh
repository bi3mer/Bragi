#!/bin/bash
cmake ..
cmake --build .
ctest -VV
