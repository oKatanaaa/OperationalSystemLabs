//
// Created by Shoto on 2/26/2019.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "SocketBasedEntity.h"

SocketBasedEntity::SocketBasedEntity() {
    std::cout << "Initializing socket based entity..." << std::endl;
    if(WSAStartup(0x0202, (WSADATA*)&buff[0])) {
        std::cout << "Cannot initialize wsa.";
        throw CANNOT_INIT_WSA;
    }
    std::cout << "WSA is initialized." << std::endl;

    if((this->entity_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Cannot create my_socket.";
        WSACleanup();
        throw CANNOT_CREATE_SOCKET;
    }
    std::cout << "Socket is created." << std::endl;


}

void SocketBasedEntity::close_socket()  {
    closesocket(this->entity_socket);
}

SocketBasedEntity::~SocketBasedEntity() {
    closesocket(this->entity_socket);
}