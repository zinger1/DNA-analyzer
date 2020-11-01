//
// Created by a on 11/1/20.
//

#ifndef DNA_VALID_H
#define DNA_VALID_H

#include <cstddef>
#include <vector>
#include <string>
#include "../../../../myExceptions/exceptions.h"

//typedef std::vector<std::string> args;

void validLenParams(size_t numParams, size_t num = 3);
void validIdsParams(args &params);
void validName(const std::string &name);
size_t convertStrToNum(const std::string &str);
void validId(std::string &id);

#endif //DNA_VALID_H
