//
// Created by a on 7/7/20.
//

#ifndef DNA_LOADCOMMAND_H
#define DNA_LOADCOMMAND_H


#include "../../ICommand.h"

class Load: public ICommand{
public:
    std::string run(std::vector<std::string>params);
    ~Load(){}
};


#endif //DNA_LOADCOMMAND_H
