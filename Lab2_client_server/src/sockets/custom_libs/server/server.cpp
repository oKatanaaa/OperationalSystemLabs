#include <winsock2.h>
#include <windows.h>
#include "server.h"
#include <iostream>

Server::Server(int port) : SocketBasedEntity() {
    std::cout << "Initializing the server..." << std::endl;
    this->local_addr.sin_family = AF_INET;
    this->local_addr.sin_port = htons(port);
    this->local_addr.sin_addr.s_addr = 0;

    if(bind(this->entity_socket, (sockaddr*)&local_addr, sizeof(local_addr))) {
        std::cout << "Cannot bind the socket." << std::endl;
        throw CANNOT_BIND_SOCKET;
    }
    std::cout << "Server is ready." << std::endl;
}

void Server::wait_for_client() {
    // Set listen mode for the socket
    if(listen(this->entity_socket, 0x100)) {
        std::cout << "Listen error." << std::endl;
        throw CANNOT_LISTEN;
    }

    // Connect to the client
    std::cout << "Wait for the client..." << std::endl;
    int client_addr_size = sizeof(this->client_addr);
    this->client_socket = accept(this->entity_socket,
                                 (sockaddr*)&this->client_addr,
                                 &client_addr_size);
    HOSTENT *hst = gethostbyaddr((char*)&this->client_addr.sin_addr.s_addr,
            4, AF_INET);

    std::cout << "Client connected: " << hst->h_name << std::endl;

    // We've established the connection to the client. Start messaging.
    send(this->client_socket, "Hello, client!", sizeof("Hello, client!"), 0);
    int received_bytes_count;
    while((received_bytes_count = recv(this->client_socket, &this->buff[0], sizeof(this->buff), 0)) != SOCKET_ERROR) {
        std::cout << "Client have sent: " << buff << std::endl;
        char* answer = this->listener->on_msg_received(this->buff, received_bytes_count);
        send(client_socket, answer, received_bytes_count, 0);
    }
    std::cout << "Client disconnected." << std::endl;
}

void Server::set_message_receive_listener(MessageReceiveListener *listener)  {
    this->listener = listener;
}



