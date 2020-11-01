//
// Created by a on 9/22/20.
//

#include <sstream>
#include "countCommand.h"
#include "../../../DNA/DNA_container.h"

std::string Count::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::stringstream castToNum(params[1]);
    size_t id;
    castToNum >> id;

    castToStr << DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().count(DnaSequence(params[2]));
    return  castToStr.str() + '\n';
}
