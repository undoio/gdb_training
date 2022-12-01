#include <string>
#include <vector>

struct MyData
{
    const char *label;

    int index;
    double output;

    const char *extra;
};


int main(void)
{
    MyData data = {
        "make me disappear",
        1234,
        10.1,
        "keep me",
    };

    // BREAKPOINT HERE
}
