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
    std::vector<std::string> HelloEN = { "Hi!", "Hello!", "Hi there!", "Howdy!" };
    std::vector<std::string> HelloRU = { "Привет!", "Здравствуйте.", "Здарова.", "Приветствую." };
    int a = rand() % 4;
    core::DataManager DM;
    core::print((DM.getValue("Data/Users/" + core::UserManager::yourUsername() + ".json", "Language") == "English") ? HelloEN[a] + '\n' : HelloRU[a] + '\n');
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
    for (auto s : vs) core::print(s + '\n', core::PrintColors::blue);
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
        else core::print("Unknown -- >> " + filesAndFolders[i].generic_string() + " << -- Unknown\n", core::PrintColors::red);
    }

    core::print("------------- >>> [ Files ] <<< -------------\n");

    for (size_t i = 0; i <= (files.size() - 1); i++) {
        if (files.empty()) { core::print("Files not found\n", core::PrintColors::red); break; }
        core::print(files[i].generic_string() + '\n', core::PrintColors::green);
    }

    core::print("------------- >>> [ Folders ] <<< -----------\n");

    for (size_t i = 0; i <= (folders.size() - 1); i++) {
        if (folders.empty()) { core::print("Folders not found\n", core::PrintColors::red); break; }
        core::print(folders[i].generic_string() + '\n', core::PrintColors::green);
    }
}

void OS_COMMAND_seeOnlyF(const std::vector<std::string>& args) {
    if (args[0] != "folders" && args[0] != "files") {
        core::print("Invalid 'type' argument. Only 'folders' and 'files' are allowed.\n", core::PrintColors::red);
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
        else core::print("Unknown -- >> " + filesAndFolders[i].generic_string() + " << -- Unknown\n", core::PrintColors::red);
    }

    if (args[0] == "files") {
        core::print("------------- >>> [ Files ] <<< -------------\n");

        for (size_t i = 0; i <= (files.size() - 1); i++) {
            if (files.empty()) { core::print("Files not found\n", core::PrintColors::red); break; }
            core::print(files[i].generic_string() + '\n', core::PrintColors::green);
        }
    }

    if (args[0] == "folders") {
        core::print("------------- >>> [ Folders ] <<< -----------\n");

        for (size_t i = 0; i <= (folders.size() - 1); i++) {
            if (folders.empty()) { core::print("Folders not found\n", core::PrintColors::red); break; }
            core::print(folders[i].generic_string() + '\n', core::PrintColors::green);
        }
    }
}