/**
 * @file file_writer.h
 *
 * @copyright Yuqing Qin, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <string>
#include <iostream>
#include <vector>


class FileWriter{
  public:
    void Write(std::string, std::vector<std::string>);
};

#endif  // SRC_FILE_WRITER_H_