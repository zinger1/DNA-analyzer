//
// Created by a on 9/22/20.
//

#ifndef DNA_COUNTCOMMAND_H
#define DNA_COUNTCOMMAND_H


#include "../../ICommand.h"

class Count: public ICommand {
public:
    std::string run(std::vector<std::string>params);
};



#endif //DNA_COUNTCOMMAND_H
