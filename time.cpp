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
    
    wcout << L"----------------------------------------------------------" << endl;
    cout << "Work Time: " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
}

void PrintTimeMonth() {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    // Получаем значения дня, месяца и года
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    if (day == 1 & month == 4) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"С Днем смеха!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    } 
    else if ((month >= 12) || (month <= 2)) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Зимняя пора!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }  
    else if ((month >= 12 && day == 31)) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Новый год к нам мчится, скоро всё случится...." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }  
        else if ((month >= 3) || (month <= 5)) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Весенная пора..." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }  
        else if ((month >= 6) || (month <= 8)) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"ЛЕТО!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }  
        else if ((month >= 9) || (month <= 11)) {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Осень..." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }  
    else {
        wcout << L"----------------------------------------------------------" << endl;
        wcout << L"Сегодня не особая дата." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
}