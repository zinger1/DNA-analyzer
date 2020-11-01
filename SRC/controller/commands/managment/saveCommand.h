//
// Created by a on 7/8/20.
//

#ifndef DNA_SAVECOMMAND_H
#define DNA_SAVECOMMAND_H


#include <iostream>
#include <vector>
#include "../ICommand.h"

class Save:public ICommand{
public:
    std::string run(std::vector<std::string>params);

};


#endif //DNA_SAVECOMMAND_H
