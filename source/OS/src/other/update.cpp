#include <iostream>
#include <nlohmann/json.hpp>
#include "Core/base/command/handler_commands.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"
#include "Core/experimental/event_manager.h"
#include "OS/other/time.h"

core::structDataEvents::UserDeleteEvent whenUserDeleted(core::structDataEvents::UserDeleteEvent data) {
    core::FileManager FM;
    FM.deleteFile("./Data/SpaceDOS/Users/" + data.username + ".json");
    return data;
}

core::structDataEvents::UserAddEvent whenUserAdded(core::structDataEvents::UserAddEvent data) {
    core::FileManager FM;
    if (!FM.fileExist("./Data/SpaceDOS/Users/" + data.username + ".json")) {
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

		std::ofstream file("./Data/SpaceDOS/Users/" + data.username + ".json");
		file << jsonData.dump(4) << '\n';
		file.close();
    }
    return data;
}

core::structDataEvents::UserChangeEvent whenUserChange(core::structDataEvents::UserChangeEvent data) {
    core::FileManager FM;
    FM.renameFile("./Data/SpaceDOS/Users/" + data.oldUsername + ".json", "./Data/SpaceDOS/Users/" + data.username + ".json");
    return data;
}

core::structDataEvents::NRCShutdownEvent byeByeNRC(core::structDataEvents::NRCShutdownEvent data) {
    core::FileManager FM;
    nlohmann::json jsonData = nlohmann::json::parse(
        FM.readFile("Data/SpaceDOS/Users/" + data.username + ".json")
    );
    jsonData["Latest Work Time"] = workTime();

    if (jsonData["Longer Work Time"].is_string())
        jsonData["Longer Work Time"] = jsonData["Latest Work Time"];
    else {
        std::vector<int> lowt = jsonData["Longer Work Time"].get<std::vector<int>>();
        std::vector<int> lawt = jsonData["Latest Work Time"].get<std::vector<int>>();

        int temp = lowt[0] + lowt[1] + lowt[2];
        int temp2 = lawt[0] + lawt[1] + lawt[2];
        if (temp < temp2)
            jsonData["Longer Work Time"] = jsonData["Latest Work Time"];
    }
	std::ofstream file("Data/SpaceDOS/Users/" + data.username + ".json", std::ios::out);
    file << jsonData.dump(4) << '\n';
	file.close();
    return data;
}

void addEvents() {
    core::EventManager::addEvent(whenUserDeleted);
    core::EventManager::addEvent(whenUserAdded);
    core::EventManager::addEvent(whenUserChange);
    core::EventManager::addEvent(byeByeNRC);
}