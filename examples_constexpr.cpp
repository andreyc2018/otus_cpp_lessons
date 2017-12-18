#include <iostream>
#include <array>
#include <string>

constexpr int get_size(int a, int b)
{
    return a + b;
}

int main(int, char**)
{
    std::array<int, 10> ten_array;
    std::cout << ten_array.size() << "\n";
    // int s = 5;
    // std::array<int, s> s_array;
    
    const int s = 5;
    std::array<int, s> s_array;
    std::cout << s_array.size() << "\n";

    std::array<int, get_size(3, 4)> func_array;
    std::cout << func_array.size() << "\n";

    // int a = 4;
    // int b = 5;
    // std::array<int, get_size(a, b)> func_args_array;
    // std::cout << func_args_array.size() << "\n";
    const int a = 4;
    const int b = 5;
    std::array<int, get_size(a, b)> func_args_array;
    std::cout << func_args_array.size() << "\n";

    return 0;
}
