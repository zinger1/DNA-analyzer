//
// Created by a on 9/21/20.
//

#include "lenParams.h"
#include <stdexcept>
#include <sstream>
#include "../../../DNA/DNA_container.h"
#include "../valid/valid.h"

void LenCommandParams::validArgs(args &args_cmd) {
    if(args_cmd.size() != 2){
        throw MyException("The num of params is invalid");
    }

    else if(args_cmd[1][0] != '#'){
        throw MyException("Id must start with #");
    }
    else{
        args_cmd[1] = args_cmd[1].substr(1, (args_cmd[1].length()-1));
    }


    std::stringstream castToNum(args_cmd[1]);
    size_t id;
    castToNum >> id;
    if (!DNAContainer::getDNAContainer().getMetaDataById(id)){
        throw MyException("Invalid id\n");
    }
}

