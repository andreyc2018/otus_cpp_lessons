#include "xray.h"
#include <iostream>

template <typename... Args>
void iterate(Args... args)
{
    std::cout << sizeof...(args) << "\n";
    int a[sizeof...(args)] = {(std::cout << args << ", ", 0)...};
    std::cout << "\n--\n";
}

int main(int, char**)
{
    iterate();
    iterate(1);
    iterate(1, 7.8);
    iterate(1, 7.8, "hello");

    return 0;
}

