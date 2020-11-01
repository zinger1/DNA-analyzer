//
// Created by a on 7/6/20.
//

#ifndef DNA_DNAMETADATA_H
#define DNA_DNAMETADATA_H

#include "DNASequence.h"
#include "status.h"
#include <vector>
class DNAMetaData {
public:
    DNAMetaData(const DnaSequence &dan, const std::string &name);
    DnaSequence getDnaSequence() {
        return m_dnaSequence;
    }

    std::string getName()const {
        return m_name;
    }

private:
    DnaSequence m_dnaSequence;
    Status m_status;
    std::string m_name;
//    size_t m_id;
//    static size_t s_idCount;

};


#endif //DNA_DNAMETADATA_H
