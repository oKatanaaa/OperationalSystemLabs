//
// Created by Shoto on 2/26/2019.
//
#include <winsock2.h>
#include <windows.h>
#include <iostream>

using namespace std;

#define my_port 80

int nclients = 0;

int main() {
    char buff[1024];
    if(WSAStartup(0x0202, (WSADATA*)&buff[0])) {
        cout << "Cannot initialize wsa.";
        return -1;
    }

    SOCKET mysocket;
    if((mysocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Cannot create my_socket.";
        WSACleanup();
        return -1;
    }

    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(my_port);
    local_addr.sin_addr.s_addr = 0;

    if(bind(mysocket, (sockaddr*)&local_addr, sizeof(local_addr))) {
        cout << "Cannot bind the my_socket.";
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    if(listen(mysocket, 0x100)) {
        cout << "Error listen";
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    SOCKET client_socket;
    sockaddr_in client_addr;
    // Aforementioned two rows of code are filled by the system.
    int client_addr_size = sizeof(client_addr);
    while((client_socket = accept(mysocket, (sockaddr*)&client_addr, &client_addr_size))) {
        nclients++;

        HOSTENT *hst = gethostbyaddr((char*)&client_addr.sin_addr.s_addr, 4, AF_INET);
        cout << "New client." << hst->h_name << endl;

        // We've established the connection to the client. Start messaging.
        send(client_socket, "1212", sizeof("1212"), 0);
        int bytes_recv;
        while((bytes_recv = recv(client_socket, &buff[0], sizeof(buff), 0)) != SOCKET_ERROR) {
            std::cout << "Client have sent: " << buff << endl;
            send(client_socket, &buff[0], bytes_recv, 0);
        }
        if(bytes_recv == SOCKET_ERROR)
            cout << "Socket error." << endl;
    }
    cout << "Stop processing.";
    return 0;
}