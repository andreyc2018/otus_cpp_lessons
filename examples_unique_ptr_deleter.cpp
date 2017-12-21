#include "unique_ptr_deleter.h"

void fini(int* ptr)
{
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";
    delete ptr;
}

int* init()
{
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";
    int* i = new int;
    return i;
}

int main(int, char**)
{
    std::cout << "with deleter::operator()" << "\n";
    {
        UPtr<int> i {init()};
        std::cout << "\tsizeof(int*) = " << sizeof(int*) << "\n";
        std::cout << "\tsizeof(i) = " << sizeof(i) << "\n";
    }

    std::cout << "\nwith decltype and function in ctor" << "\n";
    {
        std::unique_ptr<int, decltype(&fini)> j {init(), &fini};
        std::cout << "\tsizeof(j) = " << sizeof(j) << "\n";
    }

    return 0;
}
