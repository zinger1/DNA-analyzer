//
// Created by a on 7/5/20.
//

#include <stdexcept>
#include "newCommand.h"
#include "../../../DNA/DNA_container.h"
#include <sstream>
std::string New::run(std::vector<std::string> params){
    std::ostringstream castToStr;
    std::string data;
    DNAMetaData* dnaMetaData = new DNAMetaData(params[1], params[2]);
    DNAContainer::getDNAContainer().insertDNA(dnaMetaData);

    size_t len = dnaMetaData->getDnaSequence().getLength();
    castToStr << DNAContainer::getDNAContainer().getIdByName(dnaMetaData->getName());
    if(len>40){
        data = "[" + castToStr.str() + "] " + dnaMetaData->getName() + ": " + dnaMetaData->getDnaSequence().sliceDna(0, 32).getSequence()+ "..." + dnaMetaData->getDnaSequence().sliceDna(len-4, len-1).getSequence()+"\n";
    }
    else{
        data = "[" + castToStr.str() + "] " + dnaMetaData->getName() + ": " + dnaMetaData->getDnaSequence().getSequence() + "\n";
    }

    return data;
}