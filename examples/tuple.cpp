#include <iostream>
#include <string>
#include <tuple>

struct Human
{
    std::string name;
    std::string surname;
    int age;
};

auto foo()
{
    return std::make_tuple("name", "surname", 99);
}

struct tie
{
    using tuple_t = std::tuple<std::string, std::string, int>;
    std::string& name_;
    std::string& surname_;
    int& age_;
    
    tie(std::string name, std::string surname, int age)
        : name_(name), surname_(surname_), age_(age) {}

    tie& operator=(tuple_t t)
    {
        std::cout << "size = " << std::tuple_size<std::remove_reference<decltype(t)>::type>::value << "\n";
        // std::cout << "size = " << std::tuple_size<decltype(t)>::value << "\n";
        name_ = std::get<0>(t);
        surname_ = std::get<1>(t);
        age_ = std::get<2>(t);
        return *this;
    }
};

int main(int, char**)
{
    auto human = foo();
    
    std::cout << std::get<0>(human) << "\n";
    std::cout << std::get<1>(human) << "\n";
    std::cout << std::get<2>(human) << "\n";
    std::cout << std::get<int>(human) << "\n";
    
    std::string name;
    std::string surname;
    int age;
    
    std::tie(name, surname, age) = foo();
    std::cout << name << " " << surname << " " << age << "\n";

    using tuple_t = std::tuple<bool, int>;
    tuple_t t = std::make_tuple(true, 99);
    std::cout << "size = " << std::tuple_size<decltype(t)>::value << "\n";

    tuple_t& tr = t;
    std::cout << "size = " << std::tuple_size<std::remove_reference<decltype(tr)>::type>::value << "\n";
    std::cout << "size = " << std::tuple_size<std::remove_reference_t<decltype(tr)>>::value << "\n";
    
    // C++ 17
    // auto [a, b, c] = foo();
    // std::cout << a << " " << b << " " << c << "\n";

    return 0;
}
