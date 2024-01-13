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
        cout << "С Днем смеха!" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #1 в разделе \"Time\" сработало | Условие \"Проверить день смеха\" работает", "", 000);
    } 
    else if ((month >= 12) || (month <= 2)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Зимняя пора!" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #2 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 12 до 2\" работает", "", 000);
    }  
    else if ((month >= 12 && day == 31)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Новый год к нам мчится, скоро всё случится...." << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #3 в разделе \"Time\" сработало | Условие \"Проверить дату Нового года\" работает", "", 000);
    }  
    else if ((month >= 3) || (month <= 5)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Весенная пора..." << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #4 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 3 до 5\" работает", "", 000);
    }  
    else if ((month >= 6) || (month <= 8)) {
        wcout << "----------------------------------------------------------" << endl;
        wcout << "ЛЕТО!" << endl;
        wcout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #5 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 6 до 8\" работает", "", 000);
    }  
    else if ((month >= 9) || (month <= 11)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Осень..." << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #6 в разделе \"Time\" сработало | Условие \"Проверить месяцы периодом от 9 до 11\" работает", "", 000);
    }  
    else {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Сегодня не особая дата." << endl; // Sad :(
        wcout << L"----------------------------------------------------------" << endl;
        LogMessage(true, "Условие #-999 в разделе \"Time\" сработало | Условие \"Проверить ВОЗДУХ\" работает", "", 000);
    }
}