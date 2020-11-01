//
// Created by a on 7/6/20.
//

#include "DNA_container.h"

DNAContainer &DNAContainer::getDNAContainer() {
    static DNAContainer dna_container;
    return dna_container;
}

DNAMetaData *DNAContainer::getMetaDataById(size_t id){
    if(m_idHash.find(id) != m_idHash.end()){
        return m_idHash.at(id);
    }
    return NULL;

}

size_t DNAContainer::getIdByName(const std::string& name){
    if(m_nameHash.find(name) != m_nameHash.end()){
        return m_nameHash.at(name);
    }
    return 0;

}

DNAMetaData* DNAContainer::getDNAMetaDataByName(const std::string& name){
    if(m_idHash.find(m_nameHash[name]) != m_idHash.end()){
        return m_idHash.at(m_nameHash[name]);
    }
    return NULL;
}

bool DNAContainer::insertDNA(DNAMetaData *dnaMetaData) {
    if(m_nameHash.find(dnaMetaData->getName()) != m_nameHash.end()) {
        return false;
    }

    m_nameHash.insert(std::pair<std::string, unsigned int>(dnaMetaData->getName(), m_idDNA));
    m_idHash.insert(std::pair<unsigned int, DNAMetaData*>(m_idDNA, dnaMetaData));
    ++m_idDNA;
    return true;
}

