//
// Created by Shoto on 4/25/2019.
//

#include "SocketInstance.h"

SocketInstance::SocketInstance(std::string ip, std::string port) {
    // Template for address structure initializing
    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Initialize the address structure (line 9)
    int result = getaddrinfo("127.0.0.1", "8000", &hints, &(this->addr));
    if (result != 0) {
        freeaddrinfo(this->addr);
        throw UNABLE_TO_INITIALIZE_ADDRESS_STRUCTURE;
    }



    this->socket_descriptor = socket(this->addr->ai_family,
                                     this->addr->ai_socktype,
                                     this->addr->ai_protocol);
    if(this->socket_descriptor == INVALID_SOCKET) {
        freeaddrinfo(this->addr);
        throw INVALID_SOCKET;
    }
}

void SocketInstance::bind_socket() {
    /* Binds socket to the address passed into constructor */
    int result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);
    if(result == SOCKET_ERROR) {
        freeaddrinfo(this->addr);
        throw SOCKET_ERROR;
    }
}

void SocketInstance::set_listen_mode() {
    /* Sets the socket to listen mode. It is used for creating a server */
    // SOMAXCONN contains maximum amount of TCP connections. This amount relies on system's choice.
    if (listen(this->socket_descriptor, SOMAXCONN) == SOCKET_ERROR) {
        throw UNABLE_TO_SET_LISTEN_MODE;
    }
    this->mode = LISTEN_MODE;
}

SocketInstance* SocketInstance::accept_another_socket() {
    /* Listen for other connections. Returns pointer to the SocketInstance with RECEIVE_MODE */
    if(this->mode != LISTEN_MODE)
        throw LISTEN_MODE_IS_NOT_SET;

    unsigned long long accepted_socket_descriptor = accept(listen_socket, NULL, NULL);
    if (accepted_socket_descriptor == INVALID_SOCKET)
        throw INVALID_SOCKET;
    SocketInstance* accepted_socket = new SocketInstance();
    accepted_socket->mode = RECEIVE_MODE;
    accepted_socket->socket_descriptor = accepted_socket_descriptor;
    return accepted_socket;
}
