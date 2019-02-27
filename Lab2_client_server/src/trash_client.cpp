//
// Created by Shoto on 2/26/2019.
//
#include <winsock2.h>
#include <windows.h>
#include <iostream>


#define my_port 80
#define server_addr "127.0.0.1"

int nclients = 0;

int main() {
    // Initialize WSA
    char buff[1024];
    if(WSAStartup(0x0202, (WSADATA*)&buff[0])) {
        std::cout << "Cannot initialize wsa.";
        return -1;
    }
    // Create socket
    SOCKET mysocket;
    if((mysocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Cannot create my_socket.";
        WSACleanup();
        return -1;
    }

    // Establish connection
    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(my_port);
    HOSTENT *hst;
    // Converting IP address from string to net format

    if(inet_addr(server_addr) != INADDR_NONE) {
        dest_addr.sin_addr.s_addr = inet_addr(server_addr);
    } else if (hst = gethostbyname(server_addr)) {
        ((unsigned long*)&dest_addr.sin_addr)[0] = ((unsigned long**)hst->h_addr_list)[0][0];
    } else {
        std::cout << "Invalid address.";
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }

    // We received the server address - try to establish connection to the server
    if(connect(mysocket, (sockaddr*)&dest_addr, sizeof(dest_addr))) {
        std::cout << "Cannot connect.";
        return -1;
    }

    // We've connected to the server. Read and send messages
    int nsize;
    while((nsize = recv(mysocket, &buff[0], sizeof(buff) - 1, 0)) != SOCKET_ERROR) {
        buff[nsize] = 0;
        std::cout << "Received msg: " << buff << std::endl;
        std::cin >> &buff[0];
        if(!strcmp(&buff[0], "quit\n")) {
            std::cout << "Exit...";
            closesocket(mysocket);
            WSACleanup();
            return 0;
        }

        send(mysocket, &buff[0], nsize, 0);
    }

    std::cout << "Receive error.";
    closesocket(mysocket);
    WSACleanup();
    return -1;
}