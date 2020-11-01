//
// Created by a on 7/8/20.
//

#ifndef DNA_FILEWRITER_H
#define DNA_FILEWRITER_H

#include "IWriter.h"
#include <iostream>

class FileWriter: public IWriter {
public:
    FileWriter(std::string fileName):m_fileName(fileName){}
    void writeData(const std::string &data);
    ~FileWriter(){}

private:
    std::string m_fileName;
};


#endif //DNA_FILEWRITER_H
