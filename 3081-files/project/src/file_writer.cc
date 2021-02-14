/**
 * @file file_writer_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */  
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "src/file_writer.h"

void FileWriter::Write(std::string file, std::vector<std::string> container) {
    std::fstream output;
    output.open(file, std::ios::out | std::ios::app);

    for (int i = 0; i < container.size(); ++i) {
        output << container.at(i) << ",";
    }
    output << "\n";
    output.close();
}
