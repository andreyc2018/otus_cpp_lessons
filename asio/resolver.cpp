#include <boost/asio.hpp>

#include <iostream>

namespace ba = boost::asio;

int main(int, char *[]) {

    ba::io_service service;
    ba::ip::tcp::resolver resolver{service};
    auto query = ba::ip::tcp::resolver::query{"rambler.ru", "http"};

    auto iter = resolver.resolve(query);

    ba::ip::tcp::endpoint ep = *iter;

    std::cout << ep.address().to_string() << ":" << ep.port() << std::endl;


    return 0;
}
