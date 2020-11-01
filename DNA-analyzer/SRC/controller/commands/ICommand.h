//
// Created by a on 7/5/20.
//

#ifndef DNA_ICOMMAND_H
#define DNA_ICOMMAND_H

#include <vector>
#include <iostream>
#include "../DNA/DNAMetaData.h"
class ICommand {
public:
    virtual std::string run(std::vector<std::string>params) = 0;
    virtual ~ICommand(){}
};


#endif //DNA_ICOMMAND_H
