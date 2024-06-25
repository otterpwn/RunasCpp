#pragma once

#ifndef RUNASCPP_UTIL_H
#define RUNASCPP_UTIL_H

#include <string>

std::string getLocalHostname();
LPWSTR joinArguments(const std::vector<std::string>& args);
std::wstring toWideString(const std::string& str);

#endif //RUNASCPP_UTIL_H
