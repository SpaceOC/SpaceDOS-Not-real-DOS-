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

bool work = true;

void dosInit() {
    fileManager FM;
    dataManager DM;
    userManager UM;
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
    handlerCommands HC;
    while (work) {
        print(print::colors::aqua, ">>> ");
        std::string userInputResult;
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        getline(std::cin, userInputResult);
        if (userInputResult.substr(0, 5) == "help ") extentedHelp(userInputResult.substr(5));
        else HC.sendCommand(userInputResult);
        print("----------------------------------------------------------\n");
    }
}

void OS() {
    srand(static_cast<unsigned int>(time(0)));
    dosInit();
    userManager UM;
    print("Welcome to SpaceDOS, " + UM.yourUsername() + "!\n");
    printTimeMonth();
    addCommands();
    commandsZone();
}