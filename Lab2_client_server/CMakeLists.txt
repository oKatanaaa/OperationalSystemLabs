cmake_minimum_required(VERSION 3.13)
project(Lab2_client_server)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

add_executable(Lab2_client_server src/sockets/custom_libs/MessageReceiveListener/MessageReceiveListener.cpp src/sockets/custom_libs/MessageReceiveListener/MessageReceiveListener.h src/sockets/custom_libs/MRLImpl/MessageReceiveListenerImpl.cpp src/sockets/custom_libs/MRLImpl/MessageReceiveListenerImpl.h src/main.cpp src/sockets/custom_libs/server/server.cpp src/sockets/custom_libs/server/server.h src/sockets/custom_libs/SocketBasedEntity/SocketBasedEntity.cpp src/sockets/custom_libs/SocketBasedEntity/SocketBasedEntity.h)