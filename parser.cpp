#include "parser.h"
#include <iostream>
#include <string_view>

ArgumentParser::ArgumentParser() = default;

void ArgumentParser::SetUsername(const std::string& username) {
    username_ = username;
}

void ArgumentParser::SetPassword(const std::string& password) {
    password_ = password;
}

void ArgumentParser::SetDomain(const std::optional<std::string>& domain) {
    domain_ = domain;
}

void ArgumentParser::SetProcessPath(const std::string& processPath) {
    processPath_ = processPath;
}

void ArgumentParser::SetArgs(const std::vector<std::string>& args) {
    args_ = args;
}

const std::string& ArgumentParser::GetUsername() const {
    return username_;
}

const std::string& ArgumentParser::GetPassword() const {
    return password_;
}

const std::optional<std::string>& ArgumentParser::GetDomain() const {
    return domain_;
}

const std::string& ArgumentParser::GetProcessPath() const {
    return processPath_;
}

const std::vector<std::string>& ArgumentParser::GetArgs() const {
    return args_;
}

bool ArgumentParser::ParseArguments(int argc, char* argv[]) {
    // handle common errors: no arguments or missing required argument
    if (argc < 3) {
        std::cerr << "Error: Missing required arguments. Usage: " << argv[0] << " --username <username> --processpath <processpath> [--domain <domain>] [--args arg1 arg2 ...]" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; ++i) {
        std::string_view arg(argv[i]);

        if (arg == "--username") {
            if (i + 1 >= argc) {
                std::cerr << "Error: Missing username after --username." << std::endl;
                return false;
            }
            SetUsername(argv[i + 1]);
            // skip username value
            ++i;
        } else if (arg == "--password") {
            if (i + 1 >= argc) {
                std::cerr << "Error: Missing password after --password." << std::endl;
                return false;
            }
            SetPassword(argv[i + 1]);
            // skip password value
            ++i;
        } else if (arg == "--domain") {
            if (i + 1 >= argc) {
                std::cerr << "Error: Missing domain after --domain." << std::endl;
                return false;
            }
            SetDomain(argv[i + 1]);
            // skip domain value
            ++i;
        } else if (arg == "--processpath") {
                if (i + 1 >= argc) {
                    std::cerr << "Error: Missing process path after --processpath." << std::endl;
                    return false;
                }
                SetProcessPath(argv[i + 1]);
                // skip process path value
                ++i;
        } else if (arg == "--args") {
            // collect all remaining arguments as process arguments
            args_.clear();
            // skip --args itself
            ++i;
            while (i < argc && argv[i][0] != '-') {
                args_.push_back(argv[i]);
                ++i;
            }
            // rewind i to the argument that broke the loop (might be another option)
            --i;
        } else {
            std::cerr << "Warning: Unknown argument: " << arg << std::endl;
        }
    }

    return true;
}