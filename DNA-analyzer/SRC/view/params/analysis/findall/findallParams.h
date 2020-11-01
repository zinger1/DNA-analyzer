//
// Created by a on 9/21/20.
//

#ifndef DNA_FINDALLPARAMS_H
#define DNA_FINDALLPARAMS_H


#include "../../IParams.h"


class FindAllCommandParams: public IParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);

private:
    bool isIdParam(std::string &param);

};


#endif //DNA_FINDALLPARAMS_H
