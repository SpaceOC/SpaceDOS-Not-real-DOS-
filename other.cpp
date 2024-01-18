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
void printMessage(const bool what, const vector<string> Message) {
    if (language == "Russian" && what == true) {
        cout << Message[1] << endl;
    }
    else if (language == "English" && what == true) {
        cout << Message[0] << endl;
    }
    else if (language == "Russian" && what == false) {
        cout << Message[1];
    }
    else if (language == "English" && what == false) {
        cout << Message[0];
    }
    // Да, я гений 💀💀💀💀💀
    else if (language.empty() && (what != true || what != false ) || language.empty() && (what != true || what != false )) {
        cout << "Error in the function \"printMessage\" | Contact the developer of this application if the error persists" << endl;
    }
}

void LogMessage(string TypeDone, vector<string> Message, int ErrorCode) {
    if (Debug_Mode == "true") {
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

            vector<string> Info;

            if (TypeDone == "DONE") {
                Info = {"This action was successfully completed", "Данное действие было успешно завершено"};
            }
            else if (TypeDone == "ERROR") {
                Info = {"This action was completed with errors. You can find out more about the error code - " + to_string(ErrorCode), "Данное действие было завершено с ошибками. Подробнее можно узнать по коду ошибки - " + to_string(ErrorCode)};
            }
            else if (TypeDone == "WARN") {
                Info = {"This action was completed or not completed with minor errors. You can find out more about the error code - " + to_string(ErrorCode), "Данное действие было завершено или не завершено с незначительными ошибками. Подробнее можно узнать по коду ошибки - " + to_string(ErrorCode)};
            }
            else if (TypeDone == "PROCESSING") {
                Info = {"This action is currently in progress", "Данное действие на данный момент выполняется"};
            }
            else if (TypeDone == "INFO") {
                Info = {"Information", "Информация"};
            }
            else {
                Info = {"Unknown", "Неизвестно"};
            }

            if (language == "Russian") {
                logFile << "[Log] | [Time: " << buffer << " ] " << "| [ " << Info[1] << " ] " << Message[1] << endl;
            }
            if (language == "English") {
                logFile << "[Log] | [Time: " << buffer << " ] " << "| [ " << Info[0] << " ] " << Message[0] << endl;
            }
            logFile.close();
        } else {
            printMessage(true, {"LogMessage function error | Contact the developer of this application if the error persists", "Ошибка в работе функции \"LogMessage\" | Обратитесь к разработчику данного приложения, если ошибка не исчезает"});
        }
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