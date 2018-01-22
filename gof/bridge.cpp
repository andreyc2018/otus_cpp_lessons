// Мост (Bridge)

#include <iostream>

class ClockSignal {
public:
    virtual void now() = 0;
};

class InternelClockSignal : public ClockSignal {
    void now() override {
        std::cout << "internet clock" << std::endl;
    }
};

class LocalClockSignal : public ClockSignal {
    void now() override {
        std::cout << "internet clock" << std::endl;
    }
};

class Clock {
public:
    ClockSignal *s;
    void refresh() {
        s->now();
        display();
    }
    virtual void display() = 0;
};

class DigitalClock : public Clock {
    void display() {
        std::cout << "digital" << std::endl;
    }
};

class AnalogClock : public Clock {
    void display() {
        std::cout << "analog" << std::endl;
    }
};

int main(int, char *[])
{
    Clock *c = new DigitalClock;
    c->s = new InternelClockSignal;

    c->refresh();
}
