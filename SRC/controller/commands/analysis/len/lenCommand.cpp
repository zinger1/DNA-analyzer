//
// Created by a on 9/21/20.
//

#include "lenCommand.h"

#include <sstream>
#include "lenCommand.h"
#include "../../../DNA/DNA_container.h"

std::string Len::run(std::vector<std::string> vector){
    std::ostringstream castToStr;
    std::stringstream castToNum(vector[1]);
    size_t id;
    castToNum >> id;

    castToStr << DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().getLength();
    return  castToStr.str() + '\n';
}

