#include <iostream>

#include "parser.h"
#include "util.h"

int main(int argc, char* argv[]) {
    ArgumentParser parser;

    if (!parser.ParseArguments(argc, argv)) return 1;

    // access parsed arguments
    // mandatory arguments
    std::string username = parser.GetUsername();
    std::string password = parser.GetPassword();
    std::string processPath = parser.GetProcessPath();

    // optional arguments
    std::string domain;
    std::vector<std::string> processArgs = {};

    if (!parser.GetDomain().empty()) {
        domain = parser.GetDomain();
        std::cout << "domain supplied: " << domain << std::endl;
    } else {
        domain = getLocalHostname();
        if (domain.empty()) {
            std::cerr << "[!] Domain not supplied and failed getting hostname... quitting" << std::endl;
            return 1;
        }
    }

    processArgs = parser.GetArgs();

    return 0;
}