//
// Created by a on 9/22/20.
//

#ifndef DNA_COUNTPARAMS_H
#define DNA_COUNTPARAMS_H


#include "../../IParams.h"

class CountCommandParams: public IParams {
public:
    /*virtual*/ void validArgs(args& args_cmd);

private:
    bool isIdParam(std::string &param);
};


#endif //DNA_COUNTPARAMS_H
