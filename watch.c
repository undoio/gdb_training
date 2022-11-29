#include <stdio.h>
#include <stdlib.h>

struct foo
{
    struct bar
    {
        int baz;
    } *bar;
};

int
main(void)
{
    printf("Here we go\n");

    struct foo *foo = malloc(sizeof *foo);
    foo->bar = malloc(sizeof *foo->bar * 2);
    foo->bar[0].baz = 1;
    foo->bar[1].baz = 2;
    foo->bar->baz++;
    foo->bar++;

    return 0;
}
    


