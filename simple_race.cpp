#include <thread>

int
main(void)
{
    int ret = 42;

    {
        std::jthread t0([&ret]() {ret = 1;});
        std::jthread t1([&ret]() {ret = 0;});
    }

    return ret;
}

