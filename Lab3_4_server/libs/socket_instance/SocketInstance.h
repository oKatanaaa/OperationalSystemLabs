//
// Created by Shoto on 4/25/2019.
//

#ifndef LAB3_4_SERVER_SOCKETINSTANCE_H
#define LAB3_4_SERVER_SOCKETINSTANCE_H
#include <sstream>
#include <string>

#define _WIN32_WINNT 0x501

#include <WinSock2.h>
#include <WS2tcpip.h>

#define UNABLE_TO_INITIALIZE_ADDRESS_STRUCTURE 0
#define UNABLE_TO_SET_LISTEN_MODE 1
#define LISTEN_MODE_IS_NOT_SET 2

#define EMPTY_DESCRIPTOR 0

class SocketInstance {
public:

    // struct contains socket's address
    const int LISTEN_MODE = 1;
    const int RECEIVE_MODE = 2;
    const int INITIAL_MODE = 0;
    struct addrinfo* addr;


    SocketInstance(): socket_descriptor(EMPTY_DESCRIPTOR), addr(nullptr), mode(INITIAL_MODE) {};
    SocketInstance(std::string ip, std::string port);
    void bind_socket();
    void set_listen_mode();
    SocketInstance* accept_another_socket();

    int get_mode() { return this->mode; }
private:
    int mode;
    unsigned long long socket_descriptor;
};


#endif //LAB3_4_SERVER_SOCKETINSTANCE_H
