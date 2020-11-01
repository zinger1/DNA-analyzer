//
// Created by a on 9/16/20.
//

#include "paramsFactory.h"

#include "../creation/new/newParams.h"
#include "../creation/load/loadParams.h"
#include "../analysis/len/lenParams.h"
#include "../analysis/find/findParams.h"
#include "../analysis/findAll/findallParams.h"
#include "../analysis/count/countParams.h"

//#include "../saveCommandParams.h"
std::map<const std::string, IParams*> paramsFactory::init_map_command() {//return by value
    std::map<const std::string, IParams*> map;
    map.insert(std::pair<const std::string, IParams*>("new", new NewCommandParams));
    map.insert(std::pair<const std::string, IParams*>("load", new LoadCommandParams));
//    map.insert(std::pair<const std::string, IParams*>("save", new SaveCommandParams));
    map.insert(std::pair<const std::string, IParams*>("len", new LenCommandParams));
    map.insert(std::pair<const std::string, IParams*>("find", new FindCommandParams));
    map.insert(std::pair<const std::string, IParams*>("findall", new FindAllCommandParams));
    map.insert(std::pair<const std::string, IParams*>("count", new CountCommandParams));

    return map;
}
std::map<const std::string, IParams*> paramsFactory::s_commands_map = init_map_command();





