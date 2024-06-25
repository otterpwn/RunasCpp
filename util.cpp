#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>

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

LPWSTR joinArguments(const std::vector<std::string>& args) {
    if (args.empty()) {
        return NULL;
    }

    std::wstring joinedArgs;
    for (const std::string& arg : args) {
        joinedArgs += std::wstring(arg.begin(), arg.end()) + L" ";
    }

    // remove trailing spaces
    joinedArgs.pop_back();

    // allocate memory for the wide string (needs to be freed later)
    int len = joinedArgs.length() + 1;
    LPWSTR pJoinedArgs = new wchar_t[len];

    // copy the wide string to allocated memory
    wcscpy_s(pJoinedArgs, len, joinedArgs.c_str());

    return pJoinedArgs;
}

std::wstring toWideString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}