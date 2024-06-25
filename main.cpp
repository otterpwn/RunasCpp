#include <iostream>
#include <Windows.h>
#include <string>

#include "parser.h"
#include "util.h"

int main(int argc, char* argv[]) {
    ArgumentParser parser;

    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    RtlSecureZeroMemory(&si, sizeof(STARTUPINFO));
    RtlSecureZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    if (!parser.ParseArguments(argc, argv)) return 1;

    // access parsed arguments
    // mandatory arguments
    std::string username = parser.GetUsername();
    std::string password = parser.GetPassword();
    std::string processPath = parser.GetProcessPath();

    // optional arguments
    std::string domain;
    std::vector<std::string> processArgs = {};

    // if domain is empty, use hostname
    if (!parser.GetDomain().empty()) {
        domain = parser.GetDomain();
    } else {
        domain = getLocalHostname();
        if (domain.empty()) {
            std::cerr << "[!] Domain not supplied and failed getting hostname... quitting" << std::endl;
            return 1;
        }
    }

    processArgs = parser.GetArgs();
    LPWSTR parsedProcessArgs = joinArguments(processArgs);

    std::wstring wUsername = toWideString(username);
    std::wstring wPassword= toWideString(password);
    std::wstring wProcessPath= toWideString(processPath);
    std::wstring wDomain = toWideString(domain);


    if (!CreateProcessWithLogonW(wUsername.c_str(), wDomain.c_str(), wPassword.c_str(), LOGON_WITH_PROFILE, wProcessPath.c_str(), parsedProcessArgs, 0, NULL, NULL, &si, &pi)) {
        printf("[!] Error while creating process as %S\\%S: %lu\n", wDomain.c_str(), wUsername.c_str(), GetLastError());
        return 1;
    }

    if (pi.dwProcessId > 0)
        printf("[~] Spawned process with PID %lu as %S\\%S\n", pi.dwProcessId, wDomain.c_str(), wUsername.c_str());

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return 0;
}