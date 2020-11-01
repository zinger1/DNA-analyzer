//
// Created by a on 11/1/20.
//

#include <cstddef>
#include <sstream>
#include "../../../DNA/DNAMetaData.h"
#include "../../../DNA/DNA_container.h"
#include "../../../../myExceptions/exceptions.h"
#include "../../IParams.h"
#include "valid.h"

void validLenParams(size_t numParams, size_t num) {
    if (numParams != num) {
        throw MyException("Error: the num of params is invalid");
    }
}


void validIdsParams(args &params) {
    if(params[1][0] == '#'){
        validId(params[1]);
    }

    if(params[2][0] == '#'){
        validId(params[2]);
        DNAMetaData *metaData = DNAContainer::getDNAContainer().getMetaDataById(convertStrToNum(params[2]));
        params[2] = metaData->getDnaSequence().getSequence();
    }
}


void validName(const std::string &name) {
    try{
        DnaSequence dna = DnaSequence(name);
    }
    catch (MyException &exception){
        throw exception;
    }
}

size_t convertStrToNum(const std::string &str) {
    std::stringstream castToNum(str);
    size_t id;
    castToNum >> id;
    return id;
}

void validId(std::string &idParam) {
    idParam = idParam.substr(1, (idParam.length() - 1));
    if (!DNAContainer::getDNAContainer().getMetaDataById(convertStrToNum(idParam))){
        throw MyException("Error: invalid id");
    }
}
