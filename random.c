/* This is free and unencumbered software released into the public domain. */
#include <stdlib.h>

volatile int r;
int
main(void)
{
    r = rand();
    return 0;
}
