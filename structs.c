struct foo
{
    int a;
    int b;
    char c[32];
};

static struct foo
func(void)
{
    struct foo ret;
    return ret;
}

int
main(void)
{
    struct foo x = func();
    return x.a;
}