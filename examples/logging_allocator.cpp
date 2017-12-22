#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct logging_allocator
{
    using value_type = T;
    std::allocator<T> alloc;

    T* allocate(std::size_t n)
    {
        T* ptr = alloc.allocate(n);
        std::cerr << "allocate  : " << n << " " << ptr << "\n";
        return ptr;
    }

    void deallocate(T* ptr, std::size_t n)
    {
        std::cerr << "deallocate: " << n << " " << ptr << "\n";
        alloc.deallocate(ptr, n);
    }

    template <typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        std::cerr << "construct : " << ptr << " with " << sizeof...(args) << " args\n";
        alloc.construct(ptr, std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* ptr)
    {
        std::cerr << "destroy   : " << ptr << "\n";
        alloc.destroy(ptr);
    }
};

#define TRACE()  std::cerr << __PRETTY_FUNCTION__ << "\n"

class Foo
{
    public:
        using data_t = std::vector<int, logging_allocator<int>>;

        data_t get_by_value()
        {
            TRACE();
            return data;
        }

        const data_t& get_by_const_ref() const
        {
            TRACE();
            return data;
        }

        data_t& get_by_ref()
        {
            TRACE();
            return data;
        }

        void add_element(data_t::value_type x)
        {
            TRACE();
            data.push_back(x);
        }

    private:
        data_t data;
};

int main(int, char**)
{
    Foo f;
    std::cerr << "Adding elements\n";
    for (int i = 0; i < 2; ++i) {
        f.add_element(i+1);
    }

#if 0
    std::cout << "\nGetting by value\n";
    Foo::data_t d = f.get_by_value();
    for (auto i : d) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "\nGetting by cref\n";
    Foo::data_t c = f.get_by_const_ref();
    for (const auto& i : c) {
        std::cout << i << " ";
    }
    std::cout << "\n";
#endif

    std::cerr << "\nLoop by value\n";
    for (auto i : f.get_by_value()) {
        std::cout << i << " ";
    }
    std::cerr << "\n";

    std::cerr << "\nLoop and change by value\n";
    for (auto i : f.get_by_value()) {
        i *= 3;
        std::cout << i << " ";
    }
    std::cerr << "\n";

    std::cerr << "\nLoop by cref\n";
    for (const auto& i : f.get_by_const_ref()) {
        std::cout << i << " ";
    }
    std::cerr << "\n";

    std::cerr << "\nLoop and change by ref\n";
    for (auto& i : f.get_by_ref()) {
        i *= 3;
        std::cout << i << " ";
    }
    std::cerr << "\n";

    std::cerr << "\nLoop by cref\n";
    for (const auto& i : f.get_by_const_ref()) {
        std::cout << i << " ";
    }
    std::cerr << "\n";

    return 0;
}
