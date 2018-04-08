cmake_minimum_required(VERSION 3.9)
project(net)

set(CMAKE_CXX_STANDARD 14)

add_executable(pb protobuf.cpp protobuf.pb.cc)

add_executable(json json.cpp)

target_link_libraries(pb protobuf)
