//
// Created by a on 9/16/20.
//

#ifndef DNA_ICOMMANDSPARAMS_H
#define DNA_ICOMMANDSPARAMS_H

#include <string>
#include <vector>
#include <map>
#include "../../myExceptions/exceptions.h"

typedef std::vector<std::string> args;
class IParams {
public:
    virtual ~IParams(){}
    virtual void validArgs(args& args_cmd)=0;

};

#endif //DNA_ICOMMANDSPARAMS_H
