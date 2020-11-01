//
// Created by a on 6/30/20.
//

#include "fileReader.h"
#include "../../myExceptions/exceptions.h"
#include <fstream>
#include <iostream>
FileReader::FileReader(std::string fileName): m_fileName(fileName){
}

std::string FileReader::readData() {
    std::ifstream file(m_fileName.c_str());
    std::string data;
    try {
        if (!file.is_open()) {
            throw std::ofstream::failure("Exception opening file");
        }
    }
    catch (MyException& exception) {
        throw exception;
    }

    getline(file, data);
    file.close();


//    file.open(m_fileName.c_str());
//    if(file.is_open()){
//        getline(file, data);
//        file.close();
//    }
//    else{
//        std::cout << "Exception opening/reading file" << std::endl;
//    }

    return data;
}
