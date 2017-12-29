#include <iostream>
#include <string>

using volume = int;

void foo(volume v)
{
    std::cout << v << "\n";
}

int main(int, char**)
{
    foo(10);
    return 0;
}
