To get the assembly for the library:

gcc -fno-asynchronous-unwind-tables -s -m32 -c -o lib.o strlib.c mathlib.c
objconv -fnasm lib.o
