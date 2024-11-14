#include <iostream>
#include <nlohmann/json.hpp>
#include "Core/base/users/user_manager.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/print.h"
#include "Core/base/utils.h"

#include "OS/other/logs.h"
#include "OS/other/time.h"

void LogsManager::showCurrentLogs() {
    for (const auto& data : currentLogs)
        core::print("[ " + data.function + " - " + data.stringTime + " ] " + data.content + '\n', core::PrintColors::aqua);
}

void LogsManager::showFileLogs() {
    unsigned long long list = 0;
    unsigned long long pastList = list;
    unsigned long long fileLogsDataSize = allLogsData.size() - (allLogsData.size() == 1 ? 0 : 1);
    while (true) {

        if (fileLogsDataSize < list || allLogsData.size() == 1 <= list) {
            core::print("Error: content in the list of log pages number '"
                + std::to_string((list + 1))
                + "' does not exist!\n", core::PrintColors::red);
            list = pastList;
            LogsManager::writeLogs(__FUNCTION__, "Error: the value of 'file_logs_data_size' cannot be lower than the value of 'list'");
        }

        if (allLogsData.size() == 0) 
            break;

        pastList = list;

        for (const auto& data : allLogsData[list])
            core::print("[ " + data.function + " - " + data.stringTime + " ] " + data.content + '\n', core::PrintColors::aqua);
        
        std::cout << " --- File List: " << (list + 1) << " --- Type 'exit' to stop reading logs.\n";
        std::string userChoice;
        core::print(">>> ", core::PrintColors::aqua);
        std::cin >> userChoice;

        if (userChoice == "exit")
            break;
        else { 
            if (!core::Utils::stringIsNumbers(userChoice)) {
                std::cout << "Error!\n";
                LogsManager::writeLogs(__FUNCTION__, "Error: the 'user_choice' variable contains characters not suitable for stoi(), which may cause unexpected behavior. The value of 'user_choice': " + userChoice);
                break;
            }
            else 
                list = stoi(userChoice) - 1;
        }
    }
}

void LogsManager::writeLogs(std::string function, std::string content) {
    currentLogs.push_back({
        content, 
        function, 
        getCurrentData()
    });
}

void LogsManager::showLogs(const std::vector<std::string>& args) {
    if (args.at(0) != "in-os" && args.at(0) != "in-file") {
        core::print("Invalid 'type' argument. Only 'in-os' and 'in-file' are allowed.\n", core::PrintColors::red);
        return;
    }

    if (core::UserManager::currentUserData().havePassword()) {
        std::string password;
        core::print("Enter your password: ", core::PrintColors::light_aqua);
        while (!(std::cin >> std::ws)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::getline(std::cin, password);

        if (!core::UserManager::currentUserData().truePassword(password)) {
            core::print("Incorrect password!\n", core::PrintColors::red);
            return;
        }
    }

    if (args.at(0) == "in-os")
        LogsManager::showCurrentLogs();
    else
        LogsManager::showFileLogs();
}

void LogsManager::loadLogs() {
    core::FileManager FM;
    if (FM.fileExist("./Data/logs.json")) {
        std::ifstream logs("./Data/logs.json");
        std::string line;
        std::string temp;
        while (std::getline(logs, line)) {
            temp += line;
        }
        if (!temp._Starts_with("[")) {
            core::print("Error in reading logs.json: There is a missing '[' at the beginning of the file content!\n", core::PrintColors::red);
            return;
        }
        nlohmann::json jsonData = nlohmann::json::parse(temp);
        std::vector<LogsData> vectorTemp;
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

void LogsManager::saveLogs() {
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