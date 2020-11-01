//
// Created by a on 9/21/20.
//

#ifndef DNA_LENCOMMAND_H
#define DNA_LENCOMMAND_H

#include "../../ICommand.h"

class Len : public ICommand {
public:
    std::string run(std::vector<std::string> vector);
};

#endif //DNA_LENCOMMAND_H
