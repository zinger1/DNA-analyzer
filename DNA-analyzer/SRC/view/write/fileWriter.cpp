//
// Created by a on 7/8/20.
//

#include <fstream>
#include "fileWriter.h"

void FileWriter::writeData(const std::string &data) {
    std::ofstream file;
    try {
        file.open(m_fileName.c_str());
        file << data;
    }
    catch (const std::ofstream::failure &exeption){
        std::cout << exeption.what();
    }
    file.close();
}
