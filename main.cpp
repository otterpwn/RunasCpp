#include "parser.h"
#include <iostream>

int main(int argc, char* argv[]) {
    ArgumentParser parser;

    if (!parser.ParseArguments(argc, argv)) {
        return 1;
    }

    // access parsed arguments
    std::cout << "Username: " << parser.GetUsername() << std::endl;
    std::cout << "Password: " << parser.GetPassword() << std::endl;
    if (parser.GetDomain()) {
        std::cout << "Domain: " << parser.GetDomain().value() << std::endl;
    }
    std::cout << "Process Path: " << parser.GetProcessPath() << std::endl;
    std::cout << "Process Arguments: ";
    for (const std::string& arg : parser.GetArgs()) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;

    return 0;
}