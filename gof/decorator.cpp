// Декоратор (Decorator)

#include <iostream>

class File {
public:
    virtual void write() = 0;
};

class RawFile : public File {
    void write() override {
        std::cout << "write" << std::endl;
    }
};

class ZipFile : public File {
    File *clock_signal;

    void write() override {
        std::cout << "compress" << std::endl;
        clock_signal->write();
    }

public:
    ZipFile(File *clock_signal_) : clock_signal(clock_signal_) {};
};

int main(int, char *[])
{
    File *c = new RawFile;
    c->write();

    File *t = new ZipFile(c);
    t->write();
}
