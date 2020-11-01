//
// Created by a on 7/5/20.
//
#ifndef DNA_PARSER_H
#define DNA_PARSER_H

#include <string>
#include <vector>

class Parser{
public:
    Parser(std::string command);
    std::vector<std::string> getParsingData(){return m_parsingData;};
private:
    std::vector<std::string> m_parsingData;
};
#endif //DNA_PARSER_H
