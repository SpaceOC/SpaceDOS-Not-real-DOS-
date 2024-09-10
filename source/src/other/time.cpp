#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "OS/other/time.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/print.h"

time_t activationTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

std::vector<int> workTime() {
    time_t currentTime = time(nullptr);
    time_t workTime = difftime(currentTime, activationTime);
    int hours = workTime / 3600;
    int minutes = (workTime % 3600) / 60;
    int seconds = workTime % 60;
    return {hours, minutes, seconds};
}

std::string getCurrentData() {
    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    tm timeInfo;

    #if defined(_WIN32)
        localtime_s(&timeInfo, &currentTime);
    #else
        localtime_r(&currentTime, &timeInfo);
    #endif
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S / %d.%m.%Y", &timeInfo);
    return static_cast<std::string>(buffer);
}

void printWorkTime() {
    std::vector<int> currentWorkTime = workTime();
    core::print(core::colors::light_green, "Work Time: ");
    std::cout << std::setw(2) << std::setfill('0') << currentWorkTime[0] << ":" << std::setw(2) << std::setfill('0') << currentWorkTime[1] << ":" << std::setw(2) << std::setfill('0') << currentWorkTime[2] << '\n';
}

void printCurrentDate() {
    core::print(core::colors::light_green, "Time & Date: " + getCurrentData() + '\n');
}

void printTimeMonth() {
    time_t currentTime = time(nullptr);
    tm localTime;

    #if defined(_WIN32)
        localtime_s(&localTime, &currentTime);
    #else
        localtime_r(&currentTime, &localTime);
    #endif
    int day = localTime.tm_mday;
    int month = localTime.tm_mon + 1;
    //int year = localTime.tm_year + 1900;
    if (day == 1 && month == 4) core::print("Happy first April!\n");
    else if (month >= 12 || month <= 2) core::print("It's winter time!\n");
    else if (month >= 12 && day == 31) core::print("New Year's Eve is coming up!\n");
    else if (month >= 3 && month <= 5) core::print("Spring time...\n");
    else if (month >= 6 && month <= 8) core::print("SUMMER!\n");
    else if (month >= 9 && month <= 11) core::print("Autumn...\n");
}