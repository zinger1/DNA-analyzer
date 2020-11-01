//
// Created by a on 9/16/20.
//

#include "newParams.h"

#include "../../../DNA/DNASequence.h"
#include "../valid/valid.h"

void NewCommandParams::validArgs(args& args_cmd){
    validLenParams(args_cmd);

    try{
        DnaSequence dna = DnaSequence(args_cmd[1]);

    }
    catch (MyException &exception){
        throw exception.what();

    }

    validName(args_cmd, "seq");
    mapInsert(args_cmd);
}