#include <iostream>
#include <memory>

void fini(int* ptr)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    delete ptr;
}

struct deleter
{
    void operator()(int* ptr) {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        fini(ptr);
    }
};

int* init()
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    int* i = new int;
    return i;
}

int main(int, char**)
{
    std::unique_ptr<int, deleter> i {init()};
    std::cout << "sizeof(int*) = " << sizeof(int*) << "\n";
    std::cout << "sizeof(i) = " << sizeof(i) << "\n";

    std::unique_ptr<int, decltype(&fini)> j {init(), &fini};
    std::cout << "sizeof(j) = " << sizeof(j) << "\n";

    return 0;
}
