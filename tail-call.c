/* Compile with gcc -g3 -O3 -o tail-call tail-call.c */
#include <stdio.h>

static int __attribute__((noinline))
tail_callee(int a)
{
    printf("%d\n", a);
    return a * a;
}

static int __attribute__((noinline))
tail_caller_1(int a)
{
    return tail_callee(a + 1);
}

static int __attribute__((noinline))
tail_caller_2(int a)
{
    return tail_callee(a + 2);
}

int main(void)
{
    int a = 42;

    a = tail_caller_1(a);
    a = tail_caller_2(a);

    return tail_callee(a);
}
