#pragma once
#ifndef SPACEDOS_BASE_COMMANDS_SETTINGS_H_
#define SPACEDOS_BASE_COMMANDS_SETTINGS_H_

#include <string>
#include <vector>

class SpaceDOS_Settings {
    private:
        std::string availableAvailability = "0 - exit the settings\n1 - language";
        std::vector<std::string> languageList = {"Russian", "English"}; // Доступные языки
        bool languageExist(std::string language);
        // вывод списка доступных языков (в сокращении (Russian, English и т.д)) в одну строку
        std::string languageListLine();
        void languageChange(std::string language);
        void languageSettings();
        void settingsChoice();
    public:
        SpaceDOS_Settings();
};

#endif