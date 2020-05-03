/**
 * @file file_writer_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_MANAGER_H_
#define SRC_FILE_MANAGER_H_

#include <string>
#include <iostream>
#include <vector>

#include "src/file_writer.h"


/**
 * @brief
 * The File Writer manager is built for managing file writer class.
 */
class FileWriterManager{
    static FileWriter file_writer;
 public:
    static FileWriter GetInstance(){return file_writer;}
};

#endif  // SRC_FILE_MANAGER_H_
