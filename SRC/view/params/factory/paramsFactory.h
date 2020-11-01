//
// Created by a on 9/16/20.
//

#ifndef DNA_PARAMSFACTORY_H
#define DNA_PARAMSFACTORY_H

#include <map>
#include "../IParams.h"
//typedef std::map<const std::string, IParams*> commands_params_map;
class paramsFactory {
public:
    IParams* get_params_cmd(const std::string& cmd){ return s_commands_map.at(cmd);}
protected:
    static std::map<const std::string, IParams*> init_map_command();
private:
    static std::map<const std::string, IParams*> s_commands_map;
};


#endif //DNA_PARAMSFACTORY_H
