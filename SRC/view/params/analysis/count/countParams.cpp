//
// Created by a on 9/22/20.
//

#include <sstream>
#include "countParams.h"
#include "../../../DNA/DNA_container.h"
#include "../../../../myExceptions/exceptions.h"

void CountCommandParams::validArgs(args &args_cmd) {
    if(args_cmd.size() != 3){
        throw MyException("The num of params is invalid\n");
    }

    if(args_cmd[1][0] == '#'){
        if(!isIdParam(args_cmd[1])){
            throw;
        }
    }

    if(args_cmd[2][0] == '#'){
        if(!isIdParam(args_cmd[2])){
            throw;
        }
        std::stringstream castToNum(args_cmd[2]);
        size_t id;
        castToNum >> id;
        args_cmd[2] = DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().getSequence();
    }

    try{
        DnaSequence dna = DnaSequence(args_cmd[2]);
    }
    catch (MyException &exception){
        throw exception.what();
    }
}

bool CountCommandParams::isIdParam(std::string &param) {
    param = param.substr(1, (param.length() - 1));
    std::stringstream castToNum(param);
    size_t id;
    castToNum >> id;
    if (!DNAContainer::getDNAContainer().getMetaDataById(id)){
        throw MyException("Invalid id\n");
    }
    return true;
}
