#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h>

auto foo(const std::string s) -> decltype(s)
{
    return "43";
}

int main()
{
  int x = 42;
  const int y = x;
  decltype(y) a = y;
  const int b = y;
  std::cout << "Hello, " << a << "\n";
  std::cout << "Hello, " << typeid(foo).name() << "\n";
  int     status;
  char   *realname;
  realname = abi::__cxa_demangle(typeid(foo).name(), 0, 0, &status);
  std::cout << "Hello, " << realname << "\n";
  realname = abi::__cxa_demangle(typeid(a).name(), 0, 0, &status);
  std::cout << "Hello, " << realname << "\n";
  std::cout << "Hello, " << typeid(b).name() << "\n";
  realname = abi::__cxa_demangle(typeid(b).name(), 0, 0, &status);
  std::cout << "Hello, " << realname << "\n";
}

