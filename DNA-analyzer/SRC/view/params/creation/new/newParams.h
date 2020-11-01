//
// Created by a on 9/16/20.
//

#ifndef DNA_NEWPARAMS_H
#define DNA_NEWPARAMS_H

#include "../../IParams.h"

class NewCommandParams : public IParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);
};

#endif //DNA_NEWPARAMS_H
