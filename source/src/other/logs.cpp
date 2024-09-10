#include <iostream>
#include <nlohmann/json.hpp>
#include "Core/base/users/user_manager.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/print.h"
#include "Core/base/utils.h"

#include "OS/other/logs.h"
#include "OS/other/time.h"

void logsManager::showCurrentLogs() {
    for (const auto& data : currentLogs)
        core::print(core::colors::aqua, "[ " + data.function + " - " + data.stringTime + " ] " + data.content + '\n');
}

void logsManager::showFileLogs() {
    unsigned long long list = 0;
    unsigned long long pastList = list;
    unsigned long long fileLogsDataSize = allLogsData.size() - (allLogsData.size() == 1 ? 0 : 1);
    while (true) {

        if (fileLogsDataSize < list || allLogsData.size() == 1 <= list) {
            core::print(core::colors::red, "Error: content in the list of log pages number '"
                + std::to_string((list + 1))
                + "' does not exist!\n");
            list = pastList;
            logsManager::writeLogs(__FUNCTION__, "Error: the value of 'file_logs_data_size' cannot be lower than the value of 'list'");
        }

        if (allLogsData.size() == 0) 
            break;

        pastList = list;

        for (const auto& data : allLogsData[list])
            core::print(core::colors::aqua, "[ " + data.function + " - " + data.stringTime + " ] " + data.content + '\n');
        
        std::cout << " --- File List: " << (list + 1) << " --- Type 'exit' to stop reading logs.\n";
        std::string userChoice;
        core::print(core::colors::aqua, ">>> ");
        std::cin >> userChoice;

        if (userChoice == "exit")
            break;
        else { 
            if (!core::Utils::stringIsNumbers(userChoice)) {
                std::cout << "Error!\n";
                logsManager::writeLogs(__FUNCTION__, "Error: the 'user_choice' variable contains characters not suitable for stoi(), which may cause unexpected behavior. The value of 'user_choice': " + userChoice);
                break;
            }
            else 
                list = stoi(userChoice) - 1;
        }
    }
}

void logsManager::writeLogs(std::string function, std::string content) {
    currentLogs.push_back({
        content, 
        function, 
        getCurrentData()
    });
}

void logsManager::showLogs(const std::vector<std::string>& args) {
    if (args[0] != "in-os" && args[0] != "in-file") {
        core::print(core::colors::red, "Invalid 'type' argument. Only 'in-os' and 'file' are allowed.\n");
        return;
    }

    core::userManager UM;
    if (UM.currentUserData().havePassword()) {
        std::string password;
        core::print(core::colors::light_aqua, "Enter your password: ");
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, password);

        if (!UM.currentUserData().truePassword(password)) {
            core::print(core::colors::red, "Incorrect password!\n");
            return;
        }
    }

    if (args[0] == "in-os")
        logsManager::showCurrentLogs();
    else
        logsManager::showFileLogs();
}

void logsManager::loadLogs() {
    core::fileManager FM;
    if (FM.fileExist("./Data/logs.json")) {
        std::ifstream logs("./Data/logs.json");
        std::string line;
        std::string temp;
        while (std::getline(logs, line)) {
            temp += line;
        }
        if (!temp._Starts_with("[")) {
            core::print(core::colors::red, "Error in reading logs.json: There is a missing '[' at the beginning of the file content!\n");
            return;
        }
        nlohmann::json jsonData = nlohmann::json::parse(temp);
        std::vector<logsData> vectorTemp;
        for (const auto& list : jsonData) {
            for (const auto& data : list) {
                vectorTemp.push_back({
                    data["Content"],
                    data["Function"],
                    data["Date"]
                });
            }
            allLogsData.push_back(vectorTemp);
            vectorTemp.clear();
        }
        vectorTemp.clear();
    }
    else
        FM.createFile("./Data/logs.json");
}

void logsManager::saveLogs() {
    std::fstream logs("./Data/logs.json", std::ios::out);
    allLogsData.push_back(currentLogs);
    nlohmann::json jsonData;
    unsigned long long i = 0;
    for (const auto& logs : allLogsData) {
        for (const auto& data : logs) {
            jsonData[i].push_back({
                {"Content", data.content},
                {"Function", data.function},
                {"Date", data.stringTime}
            });
        }
        i++;
    }
    logs << jsonData.dump(4) << '\n';
}