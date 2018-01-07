#include "xray.h"
#include <iostream>

template <typename... Args>
void iterate(Args... args)
{
    std::cout << sizeof...(args) << "\n";
    printf("%d, %lf, %s\n", args...);
}

int main(int, char**)
{
    iterate(1, 7.8, "hello");

    return 0;
}

