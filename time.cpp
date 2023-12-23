#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

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
    tm* localTime = localtime(&currentTime);

    // Получаем значения дня, месяца и года
    int day = localTime->tm_mday; // День
    int month = localTime->tm_mon + 1; // Месяц
    int year = localTime->tm_year + 1900; // Год

    if (day == 1 & month == 4) {
        cout << "----------------------------------------------------------" << endl;
        cout << "С Днем смеха!" << endl;
        cout << "----------------------------------------------------------" << endl;
    } 
    else if ((month >= 12) || (month <= 2)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Зимняя пора!" << endl;
        cout << "----------------------------------------------------------" << endl;
    }  
    else if ((month >= 12 && day == 31)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Новый год к нам мчится, скоро всё случится...." << endl;
        cout << "----------------------------------------------------------" << endl;
    }  
    else if ((month >= 3) || (month <= 5)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Весенная пора..." << endl;
        cout << "----------------------------------------------------------" << endl;
    }  
    else if ((month >= 6) || (month <= 8)) {
        wcout << "----------------------------------------------------------" << endl;
        wcout << "ЛЕТО!" << endl;
        wcout << "----------------------------------------------------------" << endl;
    }  
    else if ((month >= 9) || (month <= 11)) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Осень..." << endl;
        cout << "----------------------------------------------------------" << endl;
    }  
    else {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Сегодня не особая дата." << endl; // Sad :(
        wcout << L"----------------------------------------------------------" << endl;
    }
}