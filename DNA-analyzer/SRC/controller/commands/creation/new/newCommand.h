//
// Created by a on 7/5/20.
//

#ifndef DNA_NEWCOMMAND_H
#define DNA_NEWCOMMAND_H

#include <iostream>
#include <vector>
#include "../../ICommand.h"
class New: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};


#endif //DNA_NEWCOMMAND_H
