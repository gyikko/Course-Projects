/**
 * @file util.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "src/util.h"

std::vector<std::string> Util::processOutput(std::ostringstream& input) {
    std::string sin = input.str();
    std::replace(sin.begin(), sin.end(), '\n', ' ');

    std::vector<std::string> result;
    size_t pos = 0;
    std::string token;

    while ((pos = sin.find(" ")) != std::string::npos) {
        token = sin.substr(0, pos);
        result.push_back(token);
        sin.erase(0, pos + 1);
    }
    result.push_back(sin);
    return result;
}
