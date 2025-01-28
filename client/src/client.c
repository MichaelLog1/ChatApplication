#include <winsock2.h>
#include <stdio.h>
#include <ws2tcpip.h>
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


    char* ip = "192.168.0.26";
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(2000);
    inet_pton(AF_INET, ip, &service.sin_addr.s_addr);

    if (bind(s, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        printf("Bind failed: %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return 1;
    }

    closesocket(s);
    WSACleanup();
    

    return 0;
}
