#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    LPCSTR pipe_name = "\\\\.\\pipe\\demo_pipe";
    HANDLE named_pipe = CreateNamedPipe(
            pipe_name,
            PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_MESSAGE|PIPE_WAIT,
            1,
            0,
            0,
            INFINITE,
            NULL
            );

    if(named_pipe == INVALID_HANDLE_VALUE) {
        cout << "Cannot create pipe." << endl;
        system("pause");
        return 0;
    }

    cout << "Wait for client to connect." << endl;
    if(!ConnectNamedPipe(named_pipe,NULL)) {
        cout << "Client hasn't connected." << endl;
        system("pause");
    }

    char received_data[100];
    // Read data from the pipe
    int data_count_to_read = 100;
    DWORD received_bytes_count;
    if(!ReadFile(named_pipe,received_data,data_count_to_read, &received_bytes_count,NULL)) {
        cout << "Cannot read data." << endl;
        CloseHandle(named_pipe);
        system("pause");
        return 0;
    }
    cout << "Received data: " << endl;
    cout << received_data << endl;
    CloseHandle(named_pipe);
    return 0;
}


