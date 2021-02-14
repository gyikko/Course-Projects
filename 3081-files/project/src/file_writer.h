/**
 * @file file_writer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <string>
#include <iostream>
#include <vector>

/**
 * @brief
 * This class is in charge of writing statistics results in
 * csv files.
 */
class FileWriter{
 public:
    void Write(std::string, std::vector<std::string>);
};

#endif  // SRC_FILE_WRITER_H_
