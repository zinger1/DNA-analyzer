//
// Created by a on 9/21/20.
//

#include <sstream>
#include <iterator>
#include "findallCommand.h"
#include "../../../DNA/DNA_container.h"

std::string Findall::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::stringstream castToNum(params[1]);
    std::ostringstream vts;
    size_t id;
    castToNum >> id;
    std::vector<int>result = DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSequence().findAll(DnaSequence(params[2]));
    if (!result.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(result.begin(), result.end() - 1, std::ostream_iterator<size_t>(vts, ", "));

        // Now add the last element with no delimiter
        vts << result.back();
    }

    return  vts.str() + '\n';
}
