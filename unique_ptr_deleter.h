#pragma once

#include <iostream>
#include <memory>

void fini(int* ptr);

struct deleter
{
    void operator()(int* ptr) {
        std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";
        fini(ptr);
    }
};

template <typename T>
using UPtr = std::unique_ptr<T, deleter>;
