//
// Created by Shoto on 2/27/2019.
//

#include "MessageReceiveListenerImpl.h"

char* MessageReceiveListenerImpl::on_msg_received(char *msg, int received_bytes_count) {
    return &msg[0];
}