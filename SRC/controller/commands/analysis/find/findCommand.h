//
// Created by a on 9/21/20.
//

#ifndef DNA_FINDCOMMAND_H
#define DNA_FINDCOMMAND_H

#include "../../ICommand.h"

class Find: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};


#endif //DNA_FINDCOMMAND_H
