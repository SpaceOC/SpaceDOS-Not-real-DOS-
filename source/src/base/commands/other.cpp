#include <iostream>
#include <string>
#include <vector>
#include "OS/base/commands/other.h"
#include "OS/OS_info.h"
#include "OS/base/commands/other.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"
#include "Core/base/print.h"

void OS_COMMAND_hi() {
    std::vector<std::string> Hello_EN = { "Hi!", "Hello!", "Hi there!", "Howdy!" };
    std::vector<std::string> Hello_RU = { "Привет!", "Здравствуйте.", "Здарова.", "Приветствую." };
    int a = rand() % 4;
    core::dataManager DM;
    core::userManager UM;
    core::print((DM.getValue("Data/Users/" + UM.yourUsername() + ".json", "Language") == "English") ? Hello_EN[a] + '\n' : Hello_RU[a] + '\n');
}

void OS_COMMAND_dosInfo() {
    std::cout << "SpaceDOS " << "[ " << OS_VERSION << " " << OS_VERSION_TYPE << " ] by " << OS_DEVELOPER << '\n';
}

void OS_COMMAND_logo() {
    std::vector<std::string> vs {
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣤⣤⣤)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣟⢛⠛⢛⣉⣤⣉⡀⢸⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⡿⠋⠁⠀⠈⢷⣄⠈⢿⣿⣿⡇⣼⣿⡿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠙⢷⣤⡈⠻⢧⣿⣿⠇)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⡀⢀⡀⠀⠀⠀⠀⠙⢿⣇⣼⣿⡟⠀)",
        R"(⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣶⣿⣿⠿⠁⠀⠀⢀⠂⠀⠀⠀⠪⢂⠀⠀⠀⠀⠀⣸⣿⣿⠁⠀)",
        R"(⠀⠀⠀⣠⣾⣿⡿⠋⠉⠭⠭⠭⢭⠟⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⣰⣿⡿⠁⠀⠀)",
        R"(⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠣⠄⠀⠀⠀⠀⠀⠀⢠⣾⣿⡿⠁⠀⠀⠀)",
        R"(⠀⠙⢿⣿⣷⣄⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠏⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠙⢿⣿⣷⣞⠁⠀⠀⠀⠀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠀⣼⣿⡿⠘⠳⣄⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⢠⣿⣿⠃⠀⠀⠈⠳⣤⣾⠟⠁⠀⠀⠀⠀⠀⢀⠔⢹⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⣠⣿⣿⠟⢦⡀⠀⠀⠀⠘⠳⣄⠀⠀⠀⠀⢀⠔⠁⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⢰⣿⣿⠁⢰⠃⠙⢦⡀⠀⠀⠀⠘⠷⡀⢀⡔⠁⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⣿⣿⡇⠀⡇⠀⠀⡀⠙⢦⢀⣀⣠⣴⣾⣧⡁⠀⠀⠀⢠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢰⣿⣿⠀⠘⠁⠒⠈⣀⣴⣾⣿⣿⠿⠿⠿⣿⣿⣧⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢸⣿⣿⣤⣤⣵⣶⣿⣿⡿⠟⠉⠀⠀⠀⠀⠈⠻⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠘⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)"
    };
    for (auto s : vs) core::print(core::colors::blue, s + '\n');
}

void OS_COMMAND_seeFaF() {
    std::vector<std::filesystem::path> filesAndFolders;
    
    for (auto& it : std::filesystem::recursive_directory_iterator("./"))
        filesAndFolders.push_back(it.path().generic_string());
    std::vector<std::filesystem::path> folders, files;

    for (size_t i = 0; i <= (filesAndFolders.size() - 1); i++) {
        auto status = std::filesystem::status(filesAndFolders[i]);
        if (status.type() == std::filesystem::file_type::regular)
            files.push_back(filesAndFolders[i]);
        else if (status.type() == std::filesystem::file_type::directory) 
            folders.push_back(filesAndFolders[i]);
        else core::print(core::colors::red, "Unknown -- >> " + filesAndFolders[i].generic_string() + " << -- Unknown\n");
    }

    core::print("------------- >>> [ Files ] <<< -------------\n");

    for (size_t i = 0; i <= (files.size() - 1); i++) {
        if (files.empty()) { core::print(core::colors::red, "Files not found\n"); break; }
        core::print(core::colors::green, files[i].generic_string() + '\n');
    }

    core::print("------------- >>> [ Folders ] <<< -----------\n");

    for (size_t i = 0; i <= (folders.size() - 1); i++) {
        if (folders.empty()) { core::print(core::colors::red, "Folders not found\n"); break; }
        core::print(core::colors::green, folders[i].generic_string() + '\n');
    }
}

void OS_COMMAND_seeOnlyF(const std::vector<std::string>& args) {
    if (args[0] != "folders" && args[0] != "files") {
        core::print(core::colors::red, "Invalid 'type' argument. Only 'folders' and 'files' are allowed.\n");
        return;
    }

    std::vector<std::filesystem::path> filesAndFolders;
    
    for (auto& it : std::filesystem::recursive_directory_iterator("./"))
        filesAndFolders.push_back(it.path().generic_string());
    std::vector<std::filesystem::path> folders, files;

    for (size_t i = 0; i <= (filesAndFolders.size() - 1); i++) {
        auto status = std::filesystem::status(filesAndFolders[i]);
        if (status.type() == std::filesystem::file_type::regular) {
            if (args[0] == "files")
                files.push_back(filesAndFolders[i]);
        }
        else if (status.type() == std::filesystem::file_type::directory) {
            if (args[0] == "folders")
                folders.push_back(filesAndFolders[i]);
        }
        else core::print(core::colors::red, "Unknown -- >> " + filesAndFolders[i].generic_string() + " << -- Unknown\n");
    }

    if (args[0] == "files") {
        core::print("------------- >>> [ Files ] <<< -------------\n");

        for (size_t i = 0; i <= (files.size() - 1); i++) {
            if (files.empty()) { core::print(core::colors::red, "Files not found\n"); break; }
            core::print(core::colors::green, files[i].generic_string() + '\n');
        }
    }

    if (args[0] == "folders") {
        core::print("------------- >>> [ Folders ] <<< -----------\n");

        for (size_t i = 0; i <= (folders.size() - 1); i++) {
            if (folders.empty()) { core::print(core::colors::red, "Folders not found\n"); break; }
            core::print(core::colors::green, folders[i].generic_string() + '\n');
        }
    }
}