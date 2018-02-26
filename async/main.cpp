#include <iostream>

#include "async.h"

int main(int, char *[]) {

    auto h = async::connect();
    async::receive(h, "qwe", 4);
    async::disconnect(h);

    return 0;
}
