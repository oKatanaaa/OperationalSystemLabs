cmake_minimum_required(VERSION 3.13)
project(Lab3_4_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab3_4_server main.cpp libs/socket_instance/SocketInstance.cpp libs/socket_instance/SocketInstance.h libs/server/Server.cpp libs/server/Server.h)