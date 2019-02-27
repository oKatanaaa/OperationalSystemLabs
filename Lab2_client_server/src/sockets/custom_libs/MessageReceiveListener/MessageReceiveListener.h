//
// Created by Shoto on 2/27/2019.
//

#ifndef LAB2_CLIENT_SERVER_MESSAGEPROCESSOR_H
#define LAB2_CLIENT_SERVER_MESSAGEPROCESSOR_H


class MessageReceiveListener {
public:
    virtual char* on_msg_received(char *msg, int received_bytes_count) = 0;
};


#endif //LAB2_CLIENT_SERVER_MESSAGEPROCESSOR_H
