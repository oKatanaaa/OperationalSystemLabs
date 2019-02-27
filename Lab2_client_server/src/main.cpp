#include "sockets/custom_libs/server/server.h"
#include "sockets/custom_libs/MRLImpl/MessageReceiveListenerImpl.h"

int main() {
    MessageReceiveListener* listener = new MessageReceiveListenerImpl();

    Server* server = new Server(80);
    server->set_message_receive_listener(listener);
    server->wait_for_client();
}