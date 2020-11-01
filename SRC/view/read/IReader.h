//
// Created by a on 6/30/20.
//

#ifndef DNA_IREADER_H
#define DNA_IREADER_H

#include <string>

class IReader{
public:
    virtual std::string readData() = 0;
    ~IReader(){}
};

#endif //DNA_IREADER_H
