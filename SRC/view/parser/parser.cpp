//
// Created by a on 7/5/20.
//

#include <list>
#include "parser.h"
#include <cstring>
#include <iostream>

Parser::Parser(std::string command) {
    size_t pos = 0;
    std::string token;
    std::vector<std::string>pharse;
    while ((pos = command.find(' ')) != std::string::npos)
    {
//        std::cout << token << " 11111";

        token = command.substr(0, pos);
        m_parsingData.push_back(token);
        command.erase(0, pos + 1);
    }
    m_parsingData.push_back(command);
}
