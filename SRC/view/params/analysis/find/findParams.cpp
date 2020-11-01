//
// Created by a on 9/21/20.
//

#include <stdexcept>
#include <sstream>
#include "findParams.h"
#include "../../../DNA/DNA_container.h"
#include "../valid/valid.h"
void FindCommandParams::validArgs(args &args_cmd) {
    validLenParams(args_cmd.size());
//    if(args_cmd.size() != 3){
//        throw MyException("Error: the num of params is invalid");
//    }

    validIdsParams(args_cmd);
//    if(args_cmd[1][0] == '#'){
//        validId(args_cmd[1]);
//    }
//
//    if(args_cmd[2][0] == '#'){
//        validId(args_cmd[2]);
//        std::stringstream castToNum(args_cmd[2]);
//        size_t id;
//        castToNum >> id;
//        args_cmd[2] = DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().getSequence();
//    }

    validName(args_cmd[2]);
//    try{
//        DnaSequence dna = DnaSequence(args_cmd[2]);
//    }
//    catch (MyException &exception){
//        throw exception;
//    }
}

//void FindCommandParams::isIdParam(std::string &param) {
//    param = param.substr(1, (param.length() - 1));
//    std::stringstream castToNum(param);
//    size_t id;
//    castToNum >> id;
//    if (!DNAContainer::getDNAContainer().getMetaDataById(id)){
//        throw MyException("Error: invalid id");
//    }
//}
