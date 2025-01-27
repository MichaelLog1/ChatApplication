#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    
    WSADATA wsa;
    SOCKET s;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup Failed\n");
        return 1;
    } else 
    {
        printf("WSAStartup Succeeded\n");
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (s == INVALID_SOCKET)
    {
        printf("Socket creation failed\n");
        WSACleanup();
        return 1;
    } else
    {
        printf("Socket creation succeeded\n");
    }
    

    return 0;
}
