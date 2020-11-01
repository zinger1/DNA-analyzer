//
// Created by a on 9/21/20.
//

#include <sstream>
#include "findCommand.h"
#include "../../../DNA/DNA_container.h"

std::string Find::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::stringstream castToNum(params[1]);
    size_t id;
    castToNum >> id;
    std::cout << params[2] << std::endl;
    castToStr << DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().find(DnaSequence(params[2]), 0);
    return  castToStr.str() + '\n';
}
