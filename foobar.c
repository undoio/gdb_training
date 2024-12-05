/* This is free and unencumbered software released into the public domain. */
static int
bar(int i)
{
    return i + 1;
}

int
main(void)
{
    for (int i = 0; i < 10240; i++)
    {
        i += bar(i);
    }

    return 0;
}
