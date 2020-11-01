//
// Created by a on 6/30/20.
//

#ifndef DNA_FILEREADER_H
#define DNA_FILEREADER_H

#include "IReader.h"
#include <fstream>
class FileReader: public IReader{
public:
    FileReader(std::string fileName);
    std::string readData();
    ~FileReader(){}

private:
    std::string m_fileName;
};
#endif //DNA_FILEREADER_H
