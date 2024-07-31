#include <iostream>
#include <vector>
#include <string>
#include "Core/base/users/user_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/print.h"
#include "OS/base/commands/settings.h"

bool SpaceDOS_Settings::languageExist(std::string language) {
    return std::find(languageList.begin(), languageList.end(), language) != languageList.end();
};

std::string SpaceDOS_Settings::languageListLine() {
    std::string temp = "";
    auto it = languageList.begin();

    for (auto lang : languageList) {
        if (std::next(it) == languageList.end()) { temp += lang; }
        else { temp += lang + ", "; }
        it++;
    }
    return temp;
};

 void SpaceDOS_Settings::languageChange(std::string language) {
    dataManager DM;
    userManager UM;
    DM.changeData("Data/Users/" + UM.yourUsername() + ".json", "Language", language, false);
    UM.readUserData(UM.yourUsername());
}

void SpaceDOS_Settings::languageSettings() {
    std::string selectedLanguage;
    print(print::colors::green, "Available languages: " + languageListLine() + "\n");
    print(print::colors::aqua, "Enter: ");
    while (!(std::cin >> std::ws)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        print(print::colors::aqua, "Enter: ");
    }
    getline(std::cin, selectedLanguage);
    if (languageExist(selectedLanguage)) { languageChange(selectedLanguage); }
    else {
        print(print::colors::red, "This language does not exist in the list of available languages!\n"); 
        languageSettings();
    }
}

void SpaceDOS_Settings::settingsChoice() {
    while (true) {
        print(availableAvailability + '\n');
        print(print::colors::aqua, "Enter: ");
        int choice;

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            print(print::colors::aqua, "Enter: ");
        }

        if (choice == 0) { break; }
        else if (choice == 1) { languageSettings(); }
    }
}

SpaceDOS_Settings::SpaceDOS_Settings() {
    settingsChoice();
}