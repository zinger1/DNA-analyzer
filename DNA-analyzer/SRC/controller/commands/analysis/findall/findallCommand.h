//
// Created by a on 9/21/20.
//

#ifndef DNA_FINDALLCOMMAND_H
#define DNA_FINDALLCOMMAND_H


#include <string>
#include <vector>
#include "../../ICommand.h"

class Findall: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};


#endif //DNA_FINDALLCOMMAND_H
