//
// Created by a on 6/1/20.
//
#include <cstring>
#include <new>
#include <string>
#include <iostream>
#include "DNASequence.h"


static int my_strcmp(const DnaSequence &dnaSequence1, const  DnaSequence &dnaSequence2) {
    int i = 0;
    while (i < (int) dnaSequence1.getLength() && i < (int) dnaSequence2.getLength()) {
        if (dnaSequence1[i] != dnaSequence2[i]){
            return int(&dnaSequence1 - &dnaSequence2);
        }
        i++;
    }
    if (dnaSequence1.getLength() == dnaSequence2.getLength()) {
        return 0;
    }
    return int(&dnaSequence1 - &dnaSequence2);
}

void DnaSequence::init(const char* sequence){
    if(!isValidDna(sequence)){
        throw std::invalid_argument("Invalid c_str");
    }
    m_dnaSequence  = new Nucleotide[strlen(sequence) + 1];
    m_lengthDnaSequence = strlen(sequence);
    for(size_t i = 0; i < m_lengthDnaSequence; ++i){
        if(sequence[i] >= 97 && sequence[i] <= 122){
            m_dnaSequence[i] = (char) toupper((char) (sequence[i] - 32));
        }

        else{
            m_dnaSequence[i] = sequence[i];
        }
    }
    m_dnaSequence[m_lengthDnaSequence] = '\0';
}

DnaSequence::DnaSequence() {
    std::ifstream myfile;
    myfile.open("DnaSequence.txt");
    if (!myfile.fail())
    {
        std::string dna;
        getline(myfile, dna);
        std::cout << dna;
        init(dna.c_str());
        std::cout << m_dnaSequence;
        myfile.close();
    }
}

DnaSequence::DnaSequence(const char* c_str) : m_dnaSequence(), m_lengthDnaSequence(){
        init(c_str);
}

DnaSequence::DnaSequence(const std::string &str) : m_dnaSequence(), m_lengthDnaSequence(){
        init(str.c_str());
}

DnaSequence::DnaSequence(IReader *ireader){
    init(ireader->readData().c_str());
}

DnaSequence::DnaSequence(size_t sizeAllocate) {
    m_dnaSequence = new Nucleotide[sizeAllocate];
    m_lengthDnaSequence = sizeAllocate;
}


DnaSequence::~DnaSequence() {
    delete[] m_dnaSequence;
    m_dnaSequence = NULL;
}

DnaSequence::DnaSequence(const DnaSequence &dnaSequence) {
    m_dnaSequence = new Nucleotide[dnaSequence.m_lengthDnaSequence + 1];
    for(size_t i = 0; i < dnaSequence.getLength(); ++i){
        m_dnaSequence[i] = dnaSequence.m_dnaSequence[i];
    }
    m_lengthDnaSequence = dnaSequence.m_lengthDnaSequence;
    m_dnaSequence[m_lengthDnaSequence] = '\0';
}

DnaSequence &DnaSequence::operator=(const DnaSequence &dnaSequence){
    if(this != &dnaSequence){
        Nucleotide *temp = new Nucleotide[dnaSequence.m_lengthDnaSequence + 1];
        if(temp){
            delete[] m_dnaSequence;
            for(size_t i = 0; i < dnaSequence.getLength(); ++i){
                m_dnaSequence[i] = dnaSequence.m_dnaSequence[i];
            }
            m_lengthDnaSequence = dnaSequence.m_lengthDnaSequence;
        }
    }
    m_dnaSequence[m_lengthDnaSequence] = '\0';
    return *this;
}

DnaSequence::Nucleotide &DnaSequence::operator[](size_t index) const{
    if(index >= m_lengthDnaSequence)
    {
        throw std::out_of_range("index out of range");
    }
    return m_dnaSequence[index];
}

size_t DnaSequence::getLength() const {
    return m_lengthDnaSequence;
}

std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence){
//    os << "Dna sequence: " ;
    for(size_t i = 0; i < dnaSequence.m_lengthDnaSequence; ++i){
        os << dnaSequence.m_dnaSequence[i];
    }
    os << std::endl;
//    os << "\ndna sequence length: " << dnaSequence.m_lengthDnaSequence << std::endl;
    return os;
}

bool DnaSequence::isValidDna(const char *str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if(!Nucleotide::isValidNucleotide(str[i])){
            return false;
        }
    }
    return true;
}

bool operator==(const DnaSequence &lhs, const DnaSequence &rhs){
    return !my_strcmp(lhs, rhs);
}

bool operator!=(const DnaSequence &lhs, const DnaSequence &rhs){
    return my_strcmp(lhs, rhs);
}

DnaSequence::Nucleotide &DnaSequence::Nucleotide::operator=(const char c) {
    if(c == '\0' || isValidNucleotide(c)){
        m_c = c;
        return *this;
    }
    else{
        throw std::invalid_argument ("this character is not valid");
    }
}

DnaSequence::Nucleotide &DnaSequence::Nucleotide::operator=(Nucleotide &nucleotide) {
    m_c = nucleotide.m_c;
    return *this;
}

bool DnaSequence::Nucleotide::isValidNucleotide(char c) {
    static std::string correct_nucleotide = "AaTtCcGg";
    return correct_nucleotide.find(c) != std::string::npos;
}

DnaSequence DnaSequence::sliceDna(size_t start, size_t end) {
    DnaSequence slicingSequence(end - start + 1);
    size_t j, i;
    for (j =0 ,i = start; j < slicingSequence.m_lengthDnaSequence; ++j, ++i) {
        slicingSequence.m_dnaSequence[j] = m_dnaSequence[i];
    }
    slicingSequence.m_dnaSequence[j] = '\0';
    return slicingSequence;
}

DnaSequence DnaSequence::pairDna() {
    DnaSequence pairDna(m_lengthDnaSequence);
    for(size_t i = m_lengthDnaSequence-1, j = 0; j < m_lengthDnaSequence; ++j, --i){
        pairDna.m_dnaSequence[j] = m_dnaSequence[i].returnPairOfNucleotide();
    }
    return pairDna;
}

char DnaSequence::Nucleotide::returnPairOfNucleotide() {
    switch (m_c){
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
    }
    return 0;
}

int DnaSequence::find(const DnaSequence &subSequence, size_t index){
    for(size_t i = index; i < m_lengthDnaSequence; ++i){
        if(sliceDna(i, i + subSequence.m_lengthDnaSequence - 1) == subSequence){
            return (int)i;
        }
    }
    return -1;

}

size_t DnaSequence::count(const DnaSequence &subSequence) {
    size_t countSubSequence = 0;
    for(int i = find(subSequence, 0); i < (int)m_lengthDnaSequence && i != -1 ; i = find(subSequence, i + 1)){
        countSubSequence++;
    }
    return countSubSequence;
}

std::vector<int> DnaSequence::findAll(const DnaSequence &subSequence) {
    std::vector<int > indexesOfSubSeq;
    for(int i = find(subSequence, 0); i < (int)m_lengthDnaSequence && i != -1 ; i = find(subSequence, i + 1)){
        indexesOfSubSeq.push_back((int)i);
    }
    return indexesOfSubSeq;
}

std::vector<int > DnaSequence::findConsensusSequences() {
    std::vector<int > startCodonIndexes = findAll("ATG");
    std::vector<int > indexesCodons;
    int endCodon;
    int lenStartCodon = (int)startCodonIndexes.size();

    for(int i =0; i < lenStartCodon; i++){
        endCodon = find("TAG", (startCodonIndexes[i] + 3));
        if(endCodon != -1 && (endCodon - startCodonIndexes[i])%3 == 0){
            indexesCodons.push_back(startCodonIndexes[i]);
            continue;
        }

        endCodon = find("TAA", (startCodonIndexes[i] + 3));
        if(endCodon != -1 && (endCodon- startCodonIndexes[i])%3 == 0){
            indexesCodons.push_back(startCodonIndexes[i]);
            continue;
        }

        endCodon = find("TGA", (startCodonIndexes[i] + 3));
        if(endCodon != -1 && (endCodon - startCodonIndexes[i])%3 == 0){
            indexesCodons.push_back(startCodonIndexes[i]);

            continue;
        }
    }
    return indexesCodons;

}


//std::vector<DnaSequence> DnaSequence::findConsensusSequences() {
//    std::vector<int > startCodonIndexes = findall("ATG");
//    std::vector<DnaSequence> codons;
//    int indexTAG;
//    int indexTAA;
//    int indexTGA;
//
//    int lenStartCodon = (int)startCodonIndexes.size();
//    for(int i =0; i < lenStartCodon; i++){
//        for(int j = i; j < lenStartCodon; ++j){
//            indexTAG = find("TAG", (startCodonIndexes[i]));
//            if(indexTAG != -1 && !(indexTAG - i)%3){
//                break;
//            }
//        }
//        for(int j = i; j < lenStartCodon; ++j){
//            indexTAA = find("TAA", (startCodonIndexes[i]));
//            if(indexTAA != -1 && !(indexTAA- i)%3){
//                break;
//            }
//        }
//        for(int j = i; j < lenStartCodon; ++j){
//            indexTGA = find("TGA", (startCodonIndexes[i]));
//            if(indexTGA != -1 && !(indexTGA - i)%3){
//                break;
//            }
//        }
//        if(indexTAG < indexTAA && indexTAG < indexTGA){
//            codons.push_back(sliceDna(i, indexTAG));
//        }
//        else if(indexTAA < indexTAG && indexTAA < indexTGA){
//            codons.push_back(sliceDna(i, indexTAA));
//        }
//        else{
//            codons.push_back(sliceDna(i, indexTGA));
//        }
//
//    }
//    return codons;
//
//}
