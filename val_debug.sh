#!/bin/sh

cd debug\
    && cmake -DCMAKE_BUILD_TYPE=Debug .. \
    && cmake --build .\
    && valgrind\
           --leak-check=full\
           --leak-resolution=high\
           --num-callers=40\
           --trace-children=yes\
           --track-fds=yes\
           --log-fd=2\
           --error-limit=no\
           --show-possibly-lost=yes\
           --show-reachable=yes\
           --show-leak-kinds=all\
           --xtree-leak=yes\
           --track-origins=yes\
           --show-mismatched-frees=yes\
           ./c-csv-test
