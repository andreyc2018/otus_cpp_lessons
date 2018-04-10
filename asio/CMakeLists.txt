cmake_minimum_required(VERSION 3.5)

project(25.asio)

# libboost-system-dev libboost-doc
find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)

add_executable(sync_client sync_client.cpp)

add_executable(sync_server sync_server.cpp)

add_executable(resolver resolver.cpp)

add_executable(chat_server chat_server.cpp)

add_executable(chat_client chat_client.cpp)

add_executable(asiohiper asiohiper.cpp)

set_target_properties(sync_client sync_server resolver asiohiper chat_server chat_client PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_DEFINITIONS BOOST_ASIO_ENABLE_HANDLER_TRACKING
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

target_link_libraries(sync_client
        ${Boost_LIBRARIES}
        )

target_link_libraries(sync_server
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        )

target_link_libraries(resolver
        ${Boost_LIBRARIES}
        )

target_link_libraries(chat_server
        ${Boost_LIBRARIES}
        )

target_link_libraries(chat_client
        ${Boost_LIBRARIES}
        )

target_link_libraries(asiohiper
        curl
        ${Boost_LIBRARIES}
        )
