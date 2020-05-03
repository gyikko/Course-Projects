/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

/**
 * @brief
 * This class is in charge of outputing the process
 */
class Util{
 public:
    static std::vector<std::string> processOutput(std::ostringstream&);
};

#endif  // SRC_UTIL_H_
