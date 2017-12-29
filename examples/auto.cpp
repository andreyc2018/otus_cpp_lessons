#include <iostream>
#include <typeinfo>
#include <string>

auto foo(auto a, auto b)
{
    return a + b;
}

auto bar(int a, float b) -> decltype(a)
{
    if (a < b)
        return a;
    return b;
}

int main(int, char**)
{
    auto a = 7;
    auto b = 8;
    
    auto r = foo(a, b);
    std::cout << "r = " << r << "\n";
    
    auto c = 7.8;
    auto d = 6.6;
    
    auto f = foo(c, d);
    std::cout << "f = " << f << "\n";
    
    auto g = foo(a, d);
    std::cout << typeid(g).name() << " g = " << g << "\n";
    
    return 0;
}

