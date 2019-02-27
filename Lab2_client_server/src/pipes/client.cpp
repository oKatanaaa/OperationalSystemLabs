#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    LPCSTR pipe_name = "\\\\.\\pipe\\demo_pipe";
    HANDLE named_pipe = CreateFile(
            pipe_name,
            GENERIC_WRITE,
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,
            0,
            NULL
            );

    // Check if we got connected to the pipe
    if(named_pipe == INVALID_HANDLE_VALUE) {
        cout << "Cannot connect to the server." << endl;
        system("pause");
        return 0;
    }

    char data[] = "connect";
    DWORD written_bytes_count;
    if(!WriteFile(
            named_pipe,
            data,
            strlen(data)+1,
            &written_bytes_count,
            NULL
            )) {
        cout << "Cannot write to the pipe" << endl;
        system("pause");
        CloseHandle(named_pipe);
        return 0;
    }

    CloseHandle(named_pipe);
    cout << "Data is sent." << endl;
    system("pause");
    return 0;
}