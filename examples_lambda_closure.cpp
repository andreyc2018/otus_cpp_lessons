#include <iostream>

struct xray
{
    xray() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    xray(const xray&) { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    xray(xray&&) { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    ~xray() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
    
    xray& operator=(const xray&) { std::cout << __PRETTY_FUNCTION__ << "\n"; return *this; }
    xray& operator=(xray&&) { std::cout << __PRETTY_FUNCTION__ << "\n"; return *this; }

};

struct closure
{
    const xray& z_;
    closure(const xray& z) : z_(z) {}
    
    int sum(int a, int b)
    {
        return a + b;
    }

    int operator()(int a, int b)
    {
        return sum(a, b);
    }
};

int main(int, char**)
{
    xray z;
    closure l(z);
    
    std::cout << l.sum(0, 0) << "\n";
    std::cout << l(0, 1) << "\n";
    
    std::cout << closure(z)(0, 3) << "\n";
    
    auto f = [z](int a, int b){ z; return a + b; };
    std::cout << f(0, 4) << "\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << [=](int a, int b){ z; return a + b; }(i, 5) << "\n";
    }

    return 0;
}
