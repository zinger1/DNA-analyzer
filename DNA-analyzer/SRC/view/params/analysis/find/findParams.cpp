//
// Created by a on 9/21/20.
//

#include <stdexcept>
#include <sstream>
#include "findParams.h"
#include "../../../DNA/DNA_container.h"
#include "../valid/valid.h"
void FindCommandParams::validArgs(args &args_cmd) {

    validLenParams(args_cmd.size());

    validIdsParams(args_cmd);

    validName(args_cmd[2]);
}
