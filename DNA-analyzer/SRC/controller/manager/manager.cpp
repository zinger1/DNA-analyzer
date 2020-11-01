//
// Created by a on 7/5/20.
//

#include "manager.h"
#include "../write/consoleWriter.h"
#include "../read/keyBoardReader.h"
#include "../parse/parser.h"
#include "../../commands/ICommand.h"
#include "../DNA/DNA_container.h"
#include "../../commands/commandsFactory/commands_factory.h"
#include "../paramsCommands/paramsFactory/params_factory.h"
#include "../../myExceptions/exceptions.h"

void Manager::start() {
    ConsoleWriter consoleWriter;
    KeyBoardReader keyBoardReader;
    CommandsFactory  commandsFactory;
    std::string input;
    while(true){
        consoleWriter.writeData("> cmd >>> ");
        input = keyBoardReader.readData();
        Parser parsing(input);
        paramsFactory paramsFactory;
        args args_cmd = parsing.getParsingData();
        try {
            paramsFactory.get_params_cmd(args_cmd[0])->validArgs(args_cmd);
            consoleWriter.writeData(commandsFactory.get_command_result(args_cmd[0])->run(args_cmd));
        }
        catch(MyException& error){
            std::cout << error.what() << std::endl;
        }
        catch(std::exception& error){
            std::cout << error.what() << std::endl;
        }
        std::cout << "\n";
    }

//    int i = 0;
//    while(true){
//            consoleWriter.writeData("\n>cmd>>> ");
//            std::string data = keyBoardReader.readData();
//            Parser parser(data);
//            Commands_factory commandFactory;
////        ICommand* icommand = commandsFactory.createCommand(parser.getParsingData());
//        try {
//
//            consoleWriter.writeData(commandFactory.get_command_result(parser.getParsingData()));
//            ++i;
//        }
//        catch (std::exception &exp){
//            std::cout << exp.what() << std::endl;
//        }
//
//        if(i == 3){
//            break;
//        }
//
//    }
}
