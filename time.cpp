#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "other.h"

using namespace std;
using namespace chrono;

time_t activationTimeT = system_clock::to_time_t(system_clock::now());

void calculateWorkTime() {
    time_t currentTime = time(nullptr);

    time_t workTime = difftime(currentTime, activationTimeT);

    int hours = workTime / 3600;
    int minutes = (workTime % 3600) / 60;
    int seconds = workTime % 60;
    
    cout << "----------------------------------------------------------" << endl;
    cout << "Work Time: " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
    cout << "----------------------------------------------------------" << endl;
}

// Текущее время
void CurrentTime() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm timeInfo;
    #if defined(_WIN32)
        localtime_s(&timeInfo, &currentTime);
    #else
        localtime_r(&currentTime, &timeInfo);
    #endif

    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S / %d.%m.%Y", &timeInfo);

    cout << "Time: " << buffer << endl;
    cout << "----------------------------------------------------------" << endl;
}

void PrintTimeMonth() {
    time_t currentTime = time(nullptr);
    tm localTime;
    #if defined(_WIN32)
        localtime_s(&localTime, &currentTime);
    #else
        localtime_r(&currentTime, &localTime);
    #endif

    // Получаем значения дня, месяца и года
    int day = localTime.tm_mday; // День
    int month = localTime.tm_mon + 1; // Месяц
    int year = localTime.tm_year + 1900; // Год

    if (day == 1 & month == 4) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"Happy Laughing Day!", "С Днём смеха!"});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #1 в разделе \"Time\" сработало | Условие \"Проверить день смеха\" работает", ""}, 000);
    } 
    else if ((month >= 12) || (month <= 2)) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"It's winter time!", "Зимняя пора!"});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #2 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 12 до 2\" работает", ""}, 000);
    }  
    else if ((month >= 12 && day == 31)) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"New Year's Eve is coming up!", "Новый год к нам мчится, скоро всё случится...."});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #3 в разделе \"Time\" сработало | Условие \"Проверить дату Нового года\" работает", ""}, 000);
    }  
    else if ((month >= 3) || (month <= 5)) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"Spring time...", "Весенная пора..."});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #4 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 3 до 5\" работает", ""}, 000);
    }  
    else if ((month >= 6) || (month <= 8)) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"SUMMER!", "ЛЕТО!"});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #5 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 6 до 8\" работает", ""}, 000);
    }  
    else if ((month >= 9) || (month <= 11)) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"Autumn...", "Осень..."});
        cout << "----------------------------------------------------------" << endl;
        //LogMessage("DONE", {"Условие #6 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 9 до 11\" работает", ""}, 000);
    }
}