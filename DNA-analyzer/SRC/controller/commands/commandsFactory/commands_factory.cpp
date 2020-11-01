//
// Created by a on 7/5/20.
//

#include <cstring>
#include "commands_factory.h"
#include "../ICommand.h"
#include "../creatin/new/newCommand.h"
#include "../creatin/load/loadCommand.h"
#include "../managment/saveCommand.h"
#include "../analysis/len/lenCommand.h"
#include "../analysis/find/findCommand.h"
#include "../analysis/findall/findallCommand.h"
#include "../analysis/count/countCommand.h"

Commands_map CommandsFactory:: init_map_command() {//return by value
    Commands_map map;
    map.insert(std::pair<const std::string, ICommand*>("new", new New));
    map.insert(std::pair<const std::string, ICommand*>("load", new Load));
    map.insert(std::pair<const std::string, ICommand*>("save", new Save));
    map.insert(std::pair<const std::string, ICommand*>("len", new Len));
    map.insert(std::pair<const std::string, ICommand*>("find", new Find));
    map.insert(std::pair<const std::string, ICommand*>("findall", new Findall));
    map.insert(std::pair<const std::string, ICommand*>("count", new Count));


    return map;
}

Commands_map CommandsFactory::s_commands_map = init_map_command();

ICommand *CommandsFactory::get_command_result(const std::string& cmd){
    return s_commands_map.at(cmd);
}
