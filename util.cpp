#include <iostream>
#include <winsock2.h>

#include "util.h"

#pragma comment(lib, "ws2_32.lib")

std::string getLocalHostname() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("Error initializing Winsock");
    }

    char hostname[256];
    int result = gethostname(hostname, sizeof(hostname));
    WSACleanup();

    if (result == 0) {
        return std::string(hostname);
    } else {
        throw std::runtime_error("Error getting hostname: " + std::to_string(WSAGetLastError()));
        return "";
    }
}