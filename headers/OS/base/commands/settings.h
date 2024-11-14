#ifndef SPACEDOS_BASE_COMMANDS_SETTINGS_H_
#define SPACEDOS_BASE_COMMANDS_SETTINGS_H_

#include <string>
#include <vector>

class SpaceDOSSettings {
    private:
        static inline std::string availableAvailability = "0 - exit the settings\n1 - language\n2 - fake loading";
        static inline std::vector<std::string> languageList = {"Russian", "English"}; // Доступные языки
        static bool languageExist(std::string language);
        // вывод списка доступных языков (в сокращении (Russian, English и т.д)) в одну строку
        static std::string languageListLine();
        static void languageChange(std::string language);
        static void languageSettings();

        static long long fakeLoadingChangeTime();
        static void fakeLoadingSettings();

        static void consoleColorSettings();

    public:
        static void settingsChoice();
        SpaceDOSSettings();
};

#endif