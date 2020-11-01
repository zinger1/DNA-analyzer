//
// Created by a on 7/7/20.
//

#ifndef DNA_DUPCOMMAND_H
#define DNA_DUPCOMMAND_H


#include "../../ICommand.h"

class Dup: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};


#endif //DNA_DUPCOMMAND_H
