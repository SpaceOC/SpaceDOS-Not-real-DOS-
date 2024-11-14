#include <iostream>
#include <map>
#include <string>
#include <nlohmann/json.hpp>
#include "Core/base/print.h"
#include "Core/base/command/handler_commands.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"
#include "OS/base/commands/main.h"
#include "OS/other/time.h"
#include "OS/other/logs.h"
#include "Core/base/filesystem/pseudo_fs.h"
#include "OS/other/update.h"
#include "OS/other/fake_loading.h"
#include "OS/other/dll_loading.h"

bool work = true;

void dosInit() {
    core::FileManager FM;
    FM.createFolders({"Data/SpaceDOS", "Data/SpaceDOS/Users"});
    for (auto user : core::UserManager::getUserMap()) {
        if (!FM.fileExist("Data/SpaceDOS/Users/" + user.first + ".json")) {
            nlohmann::json jsonData;
            jsonData["Latest Work Time"] = "";
            jsonData["Longer Work Time"] = "";
            jsonData["Fake Loading"] = false;
            jsonData["Fake Loading Data"] = {
                {"Type", 0},
                {"MS", 750},
                {"Loading Time Const", false}
            };
            jsonData["Console Settings"] = {
                {"Background", 0},
                {"Text", 7}
            };

            std::ofstream file("./Data/SpaceDOS/Users/" + user.first + ".json");
            file << jsonData.dump(4) << '\n';
            file.close();
        }
    }
}

void commandsZone() {
    while (work) {
        core::print(">>> ", core::PrintColors::aqua);
        std::string userInputResult;
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, userInputResult);
        std::vector<core::CommandObject> parsedCommands = core::HandlerCommands::parsing(userInputResult);
        for (const core::CommandObject& command : parsedCommands) {
            core::HandlerCommands::sendCommand(command);
            LogsManager::writeLogs(__FUNCTION__, "User wrote the command '" + command.name + "'");
            core::print("----------------------------------------------------------\n");
        }
    }
    LogsManager::saveLogs();
}

void OS() {
    srand(static_cast<unsigned int>(time(0)));
    dosInit();
    core::FileManager FM;
    nlohmann::json jsonData = nlohmann::json::parse(
        FM.readFile("Data/SpaceDOS/Users/" + core::UserManager::yourUsername() + ".json")
    );
    addEvents();
    addCommands();
    LogsManager::loadLogs();

    /*
    std::vector<std::string> dlls;
    for (auto& it : std::filesystem::recursive_directory_iterator("./Modules")) {
        if (std::filesystem::status(it.path().generic_string()).type() == std::filesystem::file_type::regular
            && it.path().generic_string().substr(
                it.path().generic_string().length() - 4,
                it.path().generic_string().length()) == ".dll"
        ) {
            dlls.push_back(it.path().generic_string());
        } 
    }
    if (!dlls.empty()) {
        LoadingManager LM;
        LM.setup(dlls);
        LM.start();
    }
    */

    if (jsonData["Fake Loading"].get<bool>()) {
        switch (jsonData["Fake Loading Data"]["Type"].get<int>()) {
            case 0:
                fakeLoading({'|', '/', '-', '\\'}, {"Launching SpaceDOS", "Add events", "Add commands", "Loading"}, jsonData["Fake Loading Data"]["MS"].get<long long>(), jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>());
                break;
            case 1:
                fakeLoadingPercent({"Launching SpaceDOS", "Add events", "Add commands", "Loading"}, jsonData["Fake Loading Data"]["MS"].get<long long>(), jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>());
                break;
            /*
            case 2:
                fakeLoadingBar({"Launching SpaceDOS", "Add events", "Add commands", "Loading logs"}, jsonData["Fake Loading Data"]["MS"].get<long long>(), jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>());
                break;
            case 3:
                fakeLoadingPercentAndBar({"Launching SpaceDOS", "Add events", "Add commands", "Loading logs"}, jsonData["Fake Loading Data"]["MS"].get<long long>(), jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>());
                break;
            */
            default:
                break;
        }
    }
    core::print("Welcome to SpaceDOS, " + core::UserManager::yourUsername() + "!\n");
    
    printTimeMonth();
    LogsManager::writeLogs(__FUNCTION__, "SpaceDOS has been successfully launched");
    commandsZone();
}