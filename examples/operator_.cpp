#include <iostream>
#include <string>

std::string operator "" _my(unsigned long long)
{
    return "ull";
}

std::string operator "" _my(long double)
{
    return "double";
}

std::string operator "" _my(const char*, size_t)
{
    return "char*";
}

using namespace std::string_literals;

int main(int, char**)
{
    std::cout << 123_my << "\n";
    std::cout << 123.5_my << "\n";
    std::cout << "123"_my << "\n";

    std::cout << "1\00023"s << "\n";

    return 0;
}
