//
// Created by a on 7/5/20.
//
#include <iostream>

#include "keyBoardReader.h"
std::string KeyBoardReader::readData(){
    std::string command;
    getline(std::cin, command);
    return command;
}
