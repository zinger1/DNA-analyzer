//
// Created by a on 9/17/20.
//

#include <stdexcept>
#include "loadParams.h"
#include "../../../read/fileReader.h"
#include "../valid/valid.h"
void LoadCommandParams::validArgs(args &params) {
    validLenParams(params);

    size_t pos = params[1].find('.');
    if (!(params[1].substr(pos+1, params[1].size() - 1) == "rawdna")) {
        throw MyException("Name file must soffix with 'rawdna'");
    }

    FileReader fileReader(params[1]);
    try{
        fileReader.readData();
        if(fileReader.readData().empty()){
            throw MyException("This file is empty!");
        }
    }
    catch (MyException &exception){
        throw exception;
    }

    validName(params, params[1].substr(0, pos));
    mapInsert(params);

}
