//
// Created by a on 9/16/20.
//

#ifndef DNA_NEWPARAMS_H
#define DNA_NEWPARAMS_H

#include "../../IParams.h"

class NewCommandParams : public IParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);
//private:
//    static size_t s_num_default_name;
};

#endif //DNA_NEWPARAMS_H
