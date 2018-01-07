#include "xray.h"
#include <iostream>

void iterate()
{
    std::cout << "\n--\n";
}

template <typename T, typename... Args>
void iterate(T t, Args... args)
{
    std::cout << t << ", ";
    iterate(args...);
//    int a[sizeof...(args)] = {(std::cout << args << ", ", 0)...};
}

int main(int, char**)
{
    iterate();
    iterate(1);
    iterate(1, 7.8);
    iterate(1, 7.8, "hello");

    return 0;
}

