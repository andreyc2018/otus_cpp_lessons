#include <iostream>
#include <string>

class foo
{
    public:
        virtual void m() {}
        virtual void n() {}
};

// class bar final : public foo - error in class baz declaration
class bar : public foo
{
    public:
        void m() override final {}
        // void n(int) override {}
        void n() override {}
};

class baz : public bar
{
    public:
        // void m() override {}
        void n() {}
};

int main(int, char**)
{
    return 0;
}
