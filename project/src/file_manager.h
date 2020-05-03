/**
 * @file file_writer_manager.h
 *
 * @copyright Yuqing Qin, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_MANAGER_H_
#define SRC_FILE_WRITER_MANAGER_H_

#include <string>
#include <iostream>
#include <vector>

#include "src/file_writer.h"

class FileWriterManager{
    static FileWriter file_writer;
  public:
    static FileWriter GetInstance(){return file_writer;}
};

#endif  // SRC_FILE_WRITER_MANAGER_H_