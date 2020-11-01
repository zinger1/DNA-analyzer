//
// Created by a on 7/6/20.
//

#include "DNAMetaData.h"
#include <sstream>

DNAMetaData::DNAMetaData(const DnaSequence &dna, const std::string &name)try:m_dnaSequence(dna), m_name(name){
    m_status.setStatus(E_NEW);
}catch (const std::exception &exeption){
    std::cout << exeption.what() << std::endl;
}

