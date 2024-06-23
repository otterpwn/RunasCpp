#pragma once

#ifndef RUNASCPP_PARSER_H
#define RUNASCPP_PARSER_H

#include <string>
#include <vector>
#include <optional>

struct ArgumentParser {
public:
    ArgumentParser();

    // setters for optional arguments
    void SetUsername(const std::string& username);
    void SetPassword(const std::string& password);
    void SetDomain(const std::optional<std::string>& domain);
    void SetProcessPath(const std::string& processPath);
    void SetArgs(const std::vector<std::string>& args);

    // getters for parsed arguments
    const std::string& GetUsername() const;
    const std::string& GetPassword() const;
    const std::optional<std::string>& GetDomain() const;
    const std::string& GetProcessPath() const;
    const std::vector<std::string>& GetArgs() const;

    // helper function for parsing arguments
    bool ParseArguments(int argc, char* argv[]);

private:
    std::string username_;
    std::string password_;
    std::optional<std::string> domain_;
    std::string processPath_;
    std::vector<std::string> args_;
};

#endif //RUNASCPP_PARSER_H