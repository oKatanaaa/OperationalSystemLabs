//
// Created by Shoto on 4/25/2019.
//

#include "Server.h"

Server::Server(std::string ip, std::string port) {
    this->listen_socket = SocketInstance(ip, port);
}

void Server::bind_socket() {

}
