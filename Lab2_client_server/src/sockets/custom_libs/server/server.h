//
// Created by Shoto on 2/26/2019.
//

#ifndef LAB2_CLIENT_SERVER_SERVER_H
#define LAB2_CLIENT_SERVER_SERVER_H

#endif //LAB2_CLIENT_SERVER_SERVER_H
#include "../SocketBasedEntity/SocketBasedEntity.h"
#include "../MessageReceiveListener/MessageReceiveListener.h"
#define CANNOT_BIND_SOCKET 17
#define CANNOT_LISTEN 18

class Server: public SocketBasedEntity {
private:
    SOCKET client_socket;
    sockaddr_in client_addr;

    sockaddr_in local_addr;
    MessageReceiveListener* listener;
public:
    explicit Server(int port);
    void wait_for_client();
    void set_message_receive_listener(MessageReceiveListener* listener);
};