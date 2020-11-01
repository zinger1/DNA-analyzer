//
// Created by a on 7/5/20.
//

#ifndef DNA_CONSOLEWRITER_H
#define DNA_CONSOLEWRITER_H

#include <string>
#include "IWriter.h"
class ConsoleWriter:public IWriter{
public:
    void writeData(const std::string &data);
    ~ConsoleWriter(){}
};
#endif //DNA_CONSOLEWRITER_H
