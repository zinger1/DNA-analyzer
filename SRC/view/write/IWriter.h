//
// Created by a on 7/5/20.
//

#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H

#include <string>

class IWriter{
public:
    virtual void writeData(const std::string &data) = 0;
    ~IWriter(){}
};
#endif //DNA_IWRITER_H
