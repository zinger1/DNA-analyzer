//
// Created by a on 6/1/20.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <iostream>
#include "../../test/testDna.h"
#include <string>
#include <vector>
#include <fstream>
#include "../../view/read/IReader.h"
class testDnaSequence;
class DnaSequence  {
private:
    class Nucleotide {
    public:

        Nucleotide(){}

        Nucleotide &operator=(const char c);

        Nucleotide &operator=(Nucleotide &nucleotide);

        char returnPairOfNucleotide();

        operator char() {return m_c;}

        static bool isValidNucleotide(char c);

    private:
        char m_c;

    };
    static bool isValidDna(const char *str);

    void init(const char*);

    Nucleotide *m_dnaSequence;

    size_t m_lengthDnaSequence;

    std::string getAsString() const{ return (char*)m_dnaSequence;}

public:
    DnaSequence(size_t sizeAllocate);

    DnaSequence();

    DnaSequence(const char *c_str);

    DnaSequence(const std::string &str);

    DnaSequence(IReader* ireader);

    DnaSequence(const DnaSequence &dnaSequence);

    ~DnaSequence();

    DnaSequence &operator=(const DnaSequence &dnaSequence);

    Nucleotide &operator[](size_t index) const ;

    size_t getLength() const;

    const char* getSequence()const {
        return (char*)m_dnaSequence;
    }

    DnaSequence sliceDna(size_t start, size_t end);

    DnaSequence pairDna();

    int find(const DnaSequence &subSequence, size_t index);

    size_t count(const DnaSequence &subSequence);

    std::vector<int> findAll(const DnaSequence &subSequence);

    std::vector<int> findConsensusSequences();

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &dnaSequence);

    friend class TestDnaSequence;

};

bool operator==(const DnaSequence &lhs, const DnaSequence &rhs);
bool operator!=(const DnaSequence &lhs, const DnaSequence &rhs);

#endif //DNA_DNASEQUENCE_H
