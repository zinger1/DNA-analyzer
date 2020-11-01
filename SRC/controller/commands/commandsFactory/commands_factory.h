//
// Created by a on 7/5/20.
//

#ifndef DNA_COMMANDS_FACTORY_H
#define DNA_COMMANDS_FACTORY_H

#include "../ICommand.h"
#include <string>
#include <map>
#include <vector>

typedef std::map<const std::string, ICommand*> Commands_map;
typedef std::vector<std::string> args;

class CommandsFactory {
public:
    ICommand *get_command_result(const std::string& cmd);

protected:
    static Commands_map init_map_command();

private:
    static Commands_map s_commands_map;
};



#endif //DNA_COMMANDS_FACTORY_H
