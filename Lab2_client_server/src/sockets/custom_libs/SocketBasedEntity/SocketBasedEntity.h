

#ifndef LAB2_CLIENT_SERVER_SOCKETBASEDENTITY_H
#define LAB2_CLIENT_SERVER_SOCKETBASEDENTITY_H

#endif //LAB2_CLIENT_SERVER_SOCKETBASEDENTITY_H

#define CANNOT_INIT_WSA 15
#define CANNOT_CREATE_SOCKET 16


#include <winsock2.h>
#include <ws2tcpip.h>


class SocketBasedEntity {
public:
    void close_socket();
protected:
    char buff[2048];
    SOCKET entity_socket;

    SocketBasedEntity();
    ~SocketBasedEntity();
};