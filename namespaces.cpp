#include <iostream>

namespace NameSpaceA
{
void
Foobar(void)
{
    std::cout << "Foobar from namespace A." << std::endl;
}
}

namespace NameSpaceB
{
void
Foobar(void)
{
    std::cout << "Foobar from namespace B." << std::endl;
}
}

int
main()
{

    NameSpaceA::Foobar();
    NameSpaceB::Foobar();
    return 0;
}
