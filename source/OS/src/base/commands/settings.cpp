#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "Core/base/users/user_manager.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/print.h"
#include "OS/base/commands/settings.h"
#include "Core/base/utils.h"

bool SpaceDOSSettings::languageExist(std::string language) {
    return std::find(languageList.begin(), languageList.end(), language) != languageList.end();
};

std::string SpaceDOSSettings::languageListLine() {
    std::string temp = "";
    auto it = languageList.begin();

    for (auto lang : languageList) {
        if (std::next(it) == languageList.end())
            temp += lang;
        else 
            temp += lang + ", ";
        it++;
    }
    return temp;
};

 void SpaceDOSSettings::languageChange(std::string language) {
    core::DataManager DM;
    DM.changeData("Data/Users/" + core::UserManager::yourUsername() + ".json", "Language", language, false);
    core::UserManager::readUserData(core::UserManager::yourUsername());
}

void SpaceDOSSettings::languageSettings() {
    std::string selectedLanguage;
    core::print("Available languages: " + languageListLine() + "\n", core::PrintColors::green);
    core::print("Enter: ", core::PrintColors::aqua);
    
    while (!(std::cin >> std::ws)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::getline(std::cin, selectedLanguage);

    if (languageExist(selectedLanguage))
        languageChange(selectedLanguage);
    else {
        core::print("This language does not exist in the list of available languages!\n", core::PrintColors::red); 
        languageSettings();
    }
}

long long SpaceDOSSettings::fakeLoadingChangeTime() {
    std::string newTime;
    core::print("Enter: ", core::PrintColors::aqua);
    while (!(std::cin >> std::ws)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::getline(std::cin, newTime);
    if (!core::Utils::stringIsNumbers(newTime)) newTime = "750";

    return static_cast<long long>(stoi(newTime));
}

void SpaceDOSSettings::fakeLoadingSettings() {
    std::vector<std::string> loadingTypes = {"Symbols", "Percent"};
    core::FileManager FM;
    nlohmann::json jsonData = nlohmann::json::parse(
        FM.readFile("Data/SpaceDOS/Users/" + core::UserManager::yourUsername() + ".json")
    );
    while(true) {
        std::string selected;
        core::print("-1 - Exit\n1 - ON/OFF\n2 - Change type\n3 - Unconst/Const loading time\n4 - Change time (ms)\n", core::PrintColors::green);
        core::print("Enter: ", core::PrintColors::aqua);
        
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, selected);
        if (!core::Utils::stringIsNumbers(selected)) selected = "0";

        if (selected == "-1") {
            std::ofstream file("./Data/SpaceDOS/Users/" + core::UserManager::yourUsername() + ".json");
            file << jsonData.dump(4) << '\n';
            file.close();
            break;
        }

        std::string onOrOff;
        int curType = jsonData["Fake Loading Data"]["Type"].get<int>();
        switch(stoi(selected)) {
            case 1:
                jsonData["Fake Loading"] = !jsonData["Fake Loading"].get<bool>();
                onOrOff = (jsonData["Fake Loading"].get<bool>() ? "ON" : "OFF");
                core::print("Fake Loading: " + onOrOff + "\n", core::PrintColors::aqua);
                break;
            case 2:
                curType = (curType >= 1 ? 0 : curType + 1);
                jsonData["Fake Loading Data"]["Type"] = curType;
                core::print("Fake Loading Type: " + loadingTypes.at(curType) + "\n", core::PrintColors::aqua);
                break;
            case 3:
                jsonData["Fake Loading Data"]["Loading Time Const"] = !jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>();
                onOrOff = (jsonData["Fake Loading Data"]["Loading Time Const"].get<bool>() ? "TRUE" : "FALSE");
                core::print("Fake Loading Time Const: " + onOrOff + "\n", core::PrintColors::aqua);
                break;
            case 4:
                jsonData["Fake Loading Data"]["MS"] = fakeLoadingChangeTime();
                break;
            default:
                break;
        }
    }
}

/*
void SpaceDOSSettings::consoleColorSettings() {
    core::UserManager UM;
    core::FileManager FM;
    nlohmann::json jsonData = nlohmann::json::parse(
        FM.readFile("Data/SpaceDOS/Users/" + UM.yourUsername() + ".json")
    );
    while(true) {
        std::string selected;
        core::print(core::PrintColors::green, "-1 - Exit\n1 - Background\n2 - Default text color\n");
        core::print(core::PrintColors::aqua, "Enter: ");
        
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, selected);
        if (!core::Utils::stringIsNumbers(selected)) selected = "0";

        if (selected == "-1") {
            std::ofstream file("./Data/SpaceDOS/Users/" + UM.yourUsername() + ".json");
            file << jsonData.dump(4) << '\n';
            file.close();
            break;
        }

        std::string num;
        switch(stoi(selected)) {
            case 1:
                core::print(core::light_aqua, "Enter: ");
                std::cin >> num;
                if (core::Utils::stringIsNumbers(num) && stoi(num) <= 9 && stoi(num) >= 1) {
                    jsonData["Console Settings"]["Background"] = stoi(num);
                    std::string command = "color " + num + std::to_string(jsonData["Console Settings"]["Text"].get<int>());
                    system(command.c_str());
                }
            case 2:
                core::print(core::light_aqua, "Enter: ");
                std::cin >> num;
                if (core::Utils::stringIsNumbers(num)) {
                    jsonData["Console Settings"]["Text"] = stoi(num);
                    std::string command = "color " + std::to_string(jsonData["Console Settings"]["Background"].get<int>()) + num;
                    system(command.c_str());
                }
            default:
                break;
        }
    }
}
*/

void SpaceDOSSettings::settingsChoice() {
    while (true) {
        core::print(availableAvailability + '\n');
        core::print("Enter: ", core::PrintColors::aqua);
        int choice;
        
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            core::print("Enter: ", core::PrintColors::aqua);
        }

        switch (choice) {
            case 0:
                return;
                break;
            case 1:
                languageSettings();
                break;
            case 2:
                fakeLoadingSettings();
                break;
            /*
            case 3:
                consoleColorSettings();
                break;
            */
        }
    }
}

SpaceDOSSettings::SpaceDOSSettings() {}