//
// Created by a on 11/1/20.
//

#ifndef DNA_VALID_H
#define DNA_VALID_H

#include <string>
#include <map>
#include <vector>

#include "../../../../myExceptions/exceptions.h"

typedef std::vector<std::string> args;
void validLenParams(args& args_cmd);
void validName(args& args_cmd, const std::string &defaultName);
void mapInsert(args& args_cmd);

#endif //DNA_VALID_H
