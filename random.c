#include <stdlib.h>

volatile int r;
int
main(void)
{
    r = rand();
    return 0;
}
