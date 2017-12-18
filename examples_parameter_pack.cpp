#include <iostream>

class Base
{
    public:
        template<typename T, typename... Args>
        static T* makePtr(const char* name, Args... args)
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name << "\n";
            T* ptr = new T(name, args...);
            return ptr;
        }
};

class D1 : public Base
{
    public:
        static D1* makePtr(const char* name)
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name << "\n";
            return Base::makePtr<D1>(name);
        }

        D1(const char* name) : name_(name)
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name_ << "\n";
        }

        ~D1()
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name_ << "\n";
        }

    private:
        const char* name_;
};

class D2 : public Base
{
    public:
        static D2* makePtr(const char* name, int flag)
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name << "\n";
            return Base::makePtr<D2>(name, flag);
        }

        D2(const char* name, int flag) : name_(name), flag_(flag)
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name_ << "\n";
        }

        ~D2()
        {
            std::cout << __PRETTY_FUNCTION__ << " " << name_ << "\n";
        }

    private:
        const char* name_;
        int flag_;
};

int main(int, char**)
{
    auto d2 = D2::makePtr("D2", 10);
    auto d1 = D1::makePtr("D1");
    
    return 0;
}
