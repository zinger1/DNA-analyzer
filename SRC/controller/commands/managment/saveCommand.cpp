//
// Created by a on 7/8/20.
//

#include "saveCommand.h"
#include "../../DNA/DNAMetaData.h"
#include "../../write/fileWriter.h"
#include "../../DNA/DNA_container.h"
std::string Save::run(std::vector<std::string> params) {
    size_t paramsSize = params.size();
    if(paramsSize < 2 || paramsSize > 3 ){
        throw std::invalid_argument("The number of arguments is invalid.\n");
    }

    std::string nameFile, name;
    if(paramsSize == 3){
        size_t pos = params[2].find('.');
        name = params[2].substr(pos+1, params[2].size() - 1);
        if(name == "rawdna"){
            nameFile = params[2];
        } else{
            throw std::invalid_argument("The nameFile must end with '.rawdna'.\n");
        }
    } else{
        nameFile = params[1] + ".rawdna";
    }
    FileWriter fileWriter(nameFile);

    fileWriter.writeData(DNAContainer::getDNAContainer().getDNAMetaDataByName(params[1])->getDnaSequence().getSequence());
    return "";
}
