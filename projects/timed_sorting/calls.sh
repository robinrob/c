#!/bin/bash

gcc -p *.c -o run

./run

gprof -b --no-graph run

exit 0