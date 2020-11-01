//
// Created by a on 7/6/20.
//

#ifndef DNA_DNA_H
#define DNA_DNA_H

#include "DNAMetaData.h"
#include <map>
class DNAContainer {
public:

    static DNAContainer &getDNAContainer();

    bool insertDNA(DNAMetaData *dnaMetaData);

    DNAMetaData *getMetaDataById(size_t id);

    size_t getIdByName(const std::string &name);

    DNAMetaData *getDNAMetaDataByName(const std::string &name);

private:
    DNAContainer():m_idDNA(1){}
    DNAContainer(const DNAContainer &dna){}
    std::map<std::string, size_t >m_nameHash;
    std::map<size_t , DNAMetaData *>m_idHash;//print id with #
    unsigned int m_idDNA;
};


#endif //DNA_DNA_H
