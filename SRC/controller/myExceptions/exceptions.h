//
// Created by a on 9/22/20.
//

#ifndef DNA_EXCEPTIONS_H
#define DNA_EXCEPTIONS_H


#include <stdexcept>

class MyException: public std::exception {
public:
    MyException(const char *message);
    const char* what() const throw();


private:
    const char *m_message;
};


#endif //DNA_EXCEPTIONS_H
