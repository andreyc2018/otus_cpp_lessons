#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct allocator_new
{
    using value_type = T;

    template<typename U>
    struct rebind
    { using other = allocator_new<U>; };

    T* allocate(std::size_t n)
    {
        T* ptr = static_cast<T*>(operator new(n * sizeof (T)));
        std::cerr << "new allocate  : " << n << " " << ptr << "\n";
        return ptr;
    }

    void deallocate(T* ptr, std::size_t n)
    {
        std::cerr << "new deallocate: " << n << " " << ptr << "\n";
        operator delete(ptr, n);
    }

    template <typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        std::cerr << "new construct : " << ptr << " with " << sizeof...(args) << " args\n";
        ::new(static_cast<void*>(ptr)) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* ptr)
    {
        std::cerr << "new destroy   : " << ptr << "\n";
        ptr->~U();
    }
};

template <typename T, typename RealAllocator = std::allocator<T>>
struct logging_allocator
{
    using value_type = T;
    using allocator_type = RealAllocator;

    template<typename U>
    struct rebind
    { using other = logging_allocator<U, allocator_type>; };

    allocator_type allocator;

    T* allocate(std::size_t n)
    {
        T* ptr = allocator.allocate(n);
        std::cerr << "    allocate  : " << n << " " << ptr << "\n";
        return ptr;
    }

    void deallocate(T* ptr, std::size_t n)
    {
        std::cerr << "    deallocate: " << n << " " << ptr << "\n";
        allocator.deallocate(ptr, n);
    }

    template <typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        std::cerr << "    construct : " << ptr << " with " << sizeof...(args) << " args\n";
        allocator.construct(ptr, std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* ptr)
    {
        std::cerr << "    destroy   : " << ptr << "\n";
        allocator.destroy(ptr);
    }
};

#define TRACE()  std::cerr << __PRETTY_FUNCTION__ << "\n"

class Foo
{
    public:
        using data_t = std::vector<int,
                                   logging_allocator<int,
                                                     allocator_new<int>>>;

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
