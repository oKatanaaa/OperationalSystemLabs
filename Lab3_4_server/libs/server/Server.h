//
// Created by Shoto on 4/25/2019.
//

#ifndef LAB3_4_SERVER_SERVER_H
#define LAB3_4_SERVER_SERVER_H


#include "../socket_instance/SocketInstance.h"

class Server {
public:
    Server(std::string ip, std::string port);
    SocketInstance listen_socket;
private:
    void bind_socket();
};


#endif //LAB3_4_SERVER_SERVER_H
