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
* Message - сообщение (0 индекс - English, 1 индекс - Russian)
* Пример: printMessage(true, {"Hello world!", "Привет мир!"});
*/
void printMessage(const bool Red, const vector<string> Message) {
    if (language == "Russian" && Red == true) {
        cout << Message[1] << endl;
    }
    else if (language == "English" && Red == true) {
        cout << Message[0] << endl;
    }
    else if (language == "Russian" && Red == false) {
        cout << Message[1];
    }
    else if (language == "English" && Red == false) {
        cout << Message[0];
    }
    // Да, я гений 💀💀💀💀💀
    else if (language.empty() && (Red != true || Red != false ) || language.empty() && (Red != true || Red != false )) {
        cout << "Error in the function \"printMessage\" | Contact the developer of this application if the error persists" << endl;
    }
}

void LogMessage(const string TypeDone, const vector<string> Message, const int ErrorCode) {
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

            if (language == "Russian") {
                logFile << "[Time: " << buffer << " ] | " << Message[1] << endl;
            }
            if (language == "English") {
                logFile << "[Time: " << buffer << " ] | " << Message[0] << endl;
            }
            logFile.close();
        } else {
            printMessage(true, {"LogMessage function error | Contact the developer of this application if the error persists", "Ошибка в работе функции \"LogMessage\" | Обратитесь к разработчику данного приложения, если ошибка не исчезает"});
        }
    }
    else {
        
    }
}