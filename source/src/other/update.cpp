#include <iostream>
#include "Core/base/command/handler_commands.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"

void dosRemoveUsers() {
    core::fileManager FM;
    core::userManager UM;
    for (auto& it : std::filesystem::recursive_directory_iterator("./Data/SpaceDOS/Users")) {
        if (it.status().type() == std::filesystem::file_type::regular) {
            std::string fileName = it.path().generic_string().substr(0, it.path().generic_string().length() - 5);
            bool userFound;
            for (const auto& user : UM.getUserMap()) {
                if (user.first == fileName) {
                    userFound = true;
                    break;
                }
            }
            if (!userFound)
                FM.deleteFile(it);
        }
    }
}

void dosAddUsers() {
    core::fileManager FM;
    core::dataManager DM;
    core::userManager UM;
    for (auto& it : std::filesystem::recursive_directory_iterator("./Data/SpaceDOS/Users")) {
        if (it.status().type() == std::filesystem::file_type::regular) {
            std::string fileName = it.path().generic_string().substr(0, it.path().generic_string().length() - 5);
            for (const auto& user : UM.getUserMap()) {
                if (user.first == fileName)
                    continue;
                FM.createFile("./Data/SpaceDOS/Users" + user.first + ".json");
                std::vector<std::string> keys = { "Debug Mode", "Latest Work Time", "Longer Work Time" };
                DM.createData("Data/SpaceDOS/Users/" + user.first + ".json", keys, {"false", "", ""});
            }
        }
    }
}