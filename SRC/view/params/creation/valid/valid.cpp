//
// Created by a on 11/1/20.
//

#include <sstream>
#include "valid.h"

std::map<const std::string, size_t> s_counter_names_map;

void validLenParams(args &args_cmd) {
    if(args_cmd.size() < 2 || args_cmd.size() > 3){
        throw MyException("The num of params is invalid");
    }
}

void validName(args &args_cmd, const std::string &defaultName) {
    if(args_cmd.size() == 3) {
        if(args_cmd[2][0] == '@'){
            args_cmd[2].replace(0, 1, "");
        }
        else{
            throw MyException("Name must start with @");
        }
    }
    else{
        args_cmd.push_back(defaultName);
    }
}

void mapInsert(args &args_cmd) {
    std::ostringstream castToStr;
    if(s_counter_names_map.find(args_cmd[2]) != s_counter_names_map.end()){
        castToStr << ++s_counter_names_map.at(args_cmd[2]);
        args_cmd[2] += castToStr.str();
    }
    s_counter_names_map.insert(std::pair<const std::string, size_t>(args_cmd[2], 0));
}
