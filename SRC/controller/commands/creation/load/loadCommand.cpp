//
// Created by a on 7/7/20.
//

#include <sstream>
#include "loadCommand.h"
#include "../../../DNA/DNA_container.h"
#include "../../../read/fileReader.h"

std::string Load::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::string data;
    FileReader fileReader(params[1]);

    DNAMetaData *dnaMetaData = new DNAMetaData(fileReader.readData(), params[2]);

    DNAContainer::getDNAContainer().insertDNA(dnaMetaData);

    castToStr << DNAContainer::getDNAContainer().getIdByName(dnaMetaData->getName());
    size_t lenDNA = dnaMetaData->getDnaSequence().getLength();
    if(lenDNA <= 40){
        data = '[' + castToStr.str() + "] " + dnaMetaData->getName() + ": " + dnaMetaData->getDnaSequence().getSequence() + "\n";
    } else{
        data = '[' + castToStr.str() + "] " + dnaMetaData->getName() + ": " + dnaMetaData->getDnaSequence().sliceDna(0, 31).getSequence() + "..." + dnaMetaData->getDnaSequence().sliceDna(lenDNA - 3, lenDNA - 1).getSequence() + "\n";
    }
    return data;
}

