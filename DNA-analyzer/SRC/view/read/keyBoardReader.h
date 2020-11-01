//
// Created by a on 7/5/20.
//

#ifndef DNA_KEYBOARDREADER_H
#define DNA_KEYBOARDREADER_H

#include "IReader.h"
class KeyBoardReader: public IReader{
public:
    KeyBoardReader(){}
    std::string readData();
    ~KeyBoardReader(){}
private:
    std::string m_data;
};
#endif //DNA_KEYBOARDREADER_H
