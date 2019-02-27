//
// Created by Shoto on 2/27/2019.
//

#ifndef LAB2_CLIENT_SERVER_MESSAGERECEIVELISTENERIMPL_H
#define LAB2_CLIENT_SERVER_MESSAGERECEIVELISTENERIMPL_H

#include "../MessageReceiveListener/MessageReceiveListener.h"


class MessageReceiveListenerImpl: public MessageReceiveListener {
public:
    char* on_msg_received(char* msg, int received_bytes_count);
};


#endif //LAB2_CLIENT_SERVER_MESSAGERECEIVELISTENERIMPL_H
