#include "xray.h"
#include <iostream>

template <typename... Args>
void iterate(Args... args)
{
    std::cout << sizeof...(args) << "\n";
    printf("%d, %lf, %s\n", args...);
    std::cout << (7, 8, 9) << "\n"; // prints 9
    // {(std::cout << args)...}; // {(std::cout << 1), (std::cout << 7.8), (std::cout << "hello")}
    // {(std::cout << args, 0)...}; // {(std::cout << 1, 0), (std::cout << 7.8), (std::cout << "hello")}
    int a[sizeof...(args)] = {(std::cout << args << ", ", 0)...};
    // {(std::cout << 1, 0), (std::cout << 7.8), (std::cout << "hello")}
    // a = {0, 0, 0}
    std::cout << "\n";
    for (size_t i = 0; i < sizeof...(args); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << ", ";
    }
    std::cout << "\n";
}

int main(int, char**)
{
    iterate(1, 7.8, "hello");
    iterate(1, 7.8, "hello", 1);

    return 0;
}

