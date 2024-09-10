#include <iostream>
#include <map>
#include <string>
#include "Core/base/print.h"
#include "Core/base/command/handler_commands.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"
#include "OS/base/commands/main.h"
#include "OS/other/time.h"
#include "OS/other/logs.h"

bool work = true;

void dosInit() {
    core::fileManager FM;
    core::dataManager DM;
    core::userManager UM;
    FM.createFolders({"Data/SpaceDOS", "Data/SpaceDOS/Users"});
    for (auto user : UM.getUserMap()) {
        if (!FM.fileExist("Data/SpaceDOS/Users/" + user.first + ".json")) {
            FM.createFile("Data/SpaceDOS/Users/" + user.first + ".json");
            std::vector<std::string> keys = { "Debug Mode", "Latest Work Time", "Longer Work Time" };
            DM.createData("Data/SpaceDOS/Users/" + user.first + ".json", keys, {"false", "", ""});
        }
    }
}

void commandsZone() {
    core::handlerCommands HC;
    while (work) {
        core::print(core::colors::aqua, ">>> ");
        std::string userInputResult;
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, userInputResult);
        std::vector<core::CommandObject> parsedCommands = HC.parsing(userInputResult);
        for (const core::CommandObject& command : parsedCommands) {
            HC.sendCommand(command);
            logsManager::writeLogs(__FUNCTION__, "User wrote the command '" + command.name + "'");
            core::print("----------------------------------------------------------\n");
        }
    }
    logsManager::saveLogs();
}

void OS() {
    srand(static_cast<unsigned int>(time(0)));
    addCommands();
    logsManager::loadLogs();
    dosInit();
    core::userManager UM;
    core::print("Welcome to SpaceDOS, " + UM.yourUsername() + "!\n");
    printTimeMonth();
    logsManager::writeLogs(__FUNCTION__, "SpaceDOS has been successfully launched");
    commandsZone();
}