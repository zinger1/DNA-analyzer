//
// Created by a on 9/22/20.
//

#include "exceptions.h"



MyException::MyException(const char *message): exception(), m_message(message){
}


const char *MyException::what() const throw() {
    return m_message;
}

