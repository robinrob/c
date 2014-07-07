#!/bin/bash

gcc -c *.c
ar ruv g_lib.a gfopen.o gcalloc.o
gcc *.c *.a -o run

exit 0