#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include <conio.h>
#include "data.h"

using namespace std;
using namespace filesystem;

extern string language;
extern string Debug_Mode;

extern path logFilePath;

/* 
* true - в конце сообщение будет "\n" (endl); false - не будет
* messageEn - сообщение на английском
* messageRu - сообщение на русском
* Пример: print(true, "Hello world!", "Привет мир!");
*/
void printMessage(const bool what, const string& messageEn, const string& messageRu) {
    if (language == "Russian" && what == true) {
        cout << messageRu << endl;
    }
    else if (language == "English" && what == true) {
        cout << messageEn << endl;
    }
    else if (language == "Russian" && what == false) {
        cout << messageRu;
    }
    else if (language == "English" && what == false) {
        cout << messageEn;
    }
    // Да, я гений 💀💀💀💀💀
    else if (language.empty() && (what != true || what != false ) || language.empty() && (what != true || what != false )) {
        cout << "Error!" << endl;
    }
}

void LogMessage(bool Done, string Message_RU, string Message_EN, int ErrorCode) {
    if (Done == true && Debug_Mode == "true") {
        ofstream logFile(logFilePath, ios::app);
        if (logFile.is_open()) {
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

            if (language == "Russian") {
                logFile << "[Log | Done] | [Time: " << buffer << " ] " << Message_RU << endl;
            }
            if (language == "English") {
                logFile << "[Log | Done] | [Time: " << buffer << " ] " << Message_EN << endl;
            }
            logFile.close();
        } else {
            cout << "Error" << endl;
        }
    }
    else if (Done == false && Debug_Mode == "true") {
        ofstream logFile(logFilePath, ios::app);
        if (logFile.is_open()) {
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

            if (language == "Russian") {
                logFile << "[Log | Error] | [Time: " << buffer << " ] " << Message_RU << endl;
            }
            if (language == "English") {
                logFile << "[Log | Error] | [Time: " << buffer << " ] " << Message_EN << endl;
            }
            logFile.close();
        } else {
            cout << "Error" << endl;
        }
    }
    else if ((Done == true || Done == false) && Debug_Mode == "false") {

    }
    else {
    }
}

// [Фэйковая загрузка]
void fakeLoading(const vector<string>& symbols, string MessageOne, string MessageTwo, string MessageThree, string Message4, string GreatBruh) {
    int index = 0; // index
    for (int i = 0; i < 3; i++) {
        cout << MessageOne << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        if (_kbhit()) {
            char key = _getch();
            if (key == 27 || key == 8 || key == 32) {
                std::cout << std::endl << "Loading interrupted by user." << std::endl;
                return;
            }
        }
        system("cls");
    }
    for (int i = 3; i < 6; i++) {
        cout << MessageTwo << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        if (_kbhit()) {
            char key = _getch();
            if (key == 27 || key == 8 || key == 32) {
                std::cout << std::endl << "Loading interrupted by user." << std::endl;
                return;
            }
        }
        system("cls");
    }
    for (int i = 6; i < 8; i++) {
        cout << MessageThree << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        if (_kbhit()) {
            char key = _getch();
            if (key == 27 || key == 8 || key == 32) {
                std::cout << std::endl << "Loading interrupted by user." << std::endl;
                return;
            }
        }
        system("cls");
    }
    for (int i = 8; i < 10; i++) {
        cout << Message4 << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        if (_kbhit()) {
            char key = _getch();
            if (key == 27 || key == 8 || key == 32) {
                std::cout << std::endl << "Loading interrupted by user." << std::endl;
                return;
            }
        }
        system("cls");
    }
    cout << GreatBruh << endl;
};