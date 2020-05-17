#!/bin/sh

cd build && cmake .. && cmake --build . && ./c-csv-test
