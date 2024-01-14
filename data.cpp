#include <iostream>
#include <windows.h>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "other.h"

using namespace std;
using namespace filesystem;

string version = "1.3 Alpha - BugFix 1"; // Версия SpaceDOS

string DefaultLanguage = "English"; // Стандартный язык в SpaceDOS
string DefaultUserName = "User"; // Стандартное имя пользователя в SpaceDOS
string Debug_Mode_Default = "false"; // Дебаг моде (Великий стандарт от рукожопа)

string RealVersion;
string language; // Язык (Не стандартный)
string username; // Username (Не стандартный)
string Debug_Mode; // Дебаг моде (Не стандартный)

path dataFilePath = "Data/data.data"; // Путь для файла с данными
path logFilePath = "Data/logs.data"; // Путь для файла с логами (Начинает работать, если включить дебаг моде)
path dataTempFilePath = "Data/tempData.data"; // Путь для временного файла с новыми данными

void CreateFolders() {
    create_directory("Addons"); // Создание папки Addons (Боже зачем я всё комментирую xD)
    create_directory("Data");
    create_directory("Temp");
    create_directory("Music");
    create_directory("Texts");
}

// Проверка модов и файла AddonsList.json
void CheckAddons() {
    string path = "Addons/AddonsList.json";
    if (exists(path)) {
        LogMessage("DONE", {"", "Файл \"AddonsList.json\" найден"}, 000); // М-да.... Ничего путного я пока что не придумал для LogMessage 💀💀💀
    } 
    else {
        LogMessage("ERROR", {"", "Файл \"AddonsList.json\" не найден"}, 404);
    }
}

// Создание файла с логами
void CreateLogFile() {
    ifstream file(logFilePath);
    if (!file && Debug_Mode == "true") {
        ofstream data(logFilePath);
        if (data) {
            data.close();
        }
        else {
            cout << "Error opening the data file." << '\n';
        }
    }
    else {
        file.close();
    }
}

// Создание базового файла для сохранения стандартных настроек - Language, Username, Verifed of OOBE и Colors Console
void CreateDataFile() {
    ifstream file(dataFilePath);
    if (!file) {
        ofstream data(dataFilePath);
        if (data) {
            data << "Language: " << DefaultLanguage << '\n';
            data << "UserName: " << DefaultUserName << '\n';
            data << "Version: " << version << '\n';
            data << "Debug Mode: " << Debug_Mode_Default << '\n';
            data.close();
        }
        else {
            cout << "Error opening the data file." << '\n';
        }
    }
    else {
        file.close();
    }
}

// Функция для прочитывания стандартных данных данных (Language, Username, Verifed of OOBE и Colors Console)
void ReadDataFile() {
    ifstream data(dataFilePath);
    if (data) {
        string line;
        bool foundLanguage = false;
        bool foundUsername = false;
        bool foundVersion = false;
        bool foundDebug_Mode = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find("Language: ") != string::npos) {
                language = line.substr(10);
                LogMessage("DONE", {"", "Язык SpaceDOS на данный момент - " + language}, 000);
                foundLanguage = true;
            }
            if (!foundUsername && line.find("UserName: ") != string::npos) {
                username = line.substr(10);
                LogMessage("DONE", {"", "Текущий никнейм пользователя - " + username}, 000);
                cout << "Username: " << username << '\n';
                foundUsername = true;
            }
            if (!foundVersion && line.find("Version: ") != string::npos) {
                RealVersion = line.substr(9);
                LogMessage("DONE", {"", "Текущая версия SpaceDOS - " + version}, 000);
                cout << "Version: " << RealVersion << '\n';
                /*if (RealVersion != version) {
                    cout << "Чувак! Это что за бархатная версия?" << endl;
                }*/
                foundVersion = true;
            }
            if (!foundDebug_Mode && line.find("Debug Mode: ") != string::npos) {
                Debug_Mode = line.substr(12);
                cout << "Debug Mode: " << Debug_Mode << '\n';
                foundDebug_Mode = true;
            }
            if (foundLanguage && foundUsername && foundVersion && foundDebug_Mode) {
                LogMessage("DONE", {"", "Всё найдено - версия, юзернейм, язык и Debug Mode"}, 000);
                break;
            }
        }
        data.close();
    }
    else {
        cout << "Error opening the data file." << std::endl;
    }
}

// Функция изменения стандартных данных (Language и Username) в data.data
void EditData(const string& field, const string& value) {
    ifstream inputFile(dataFilePath);
    ofstream tempFile(dataTempFilePath);
    if (inputFile && tempFile) {
        string line;
        bool fieldFound = false;
        while (getline(inputFile, line)) {
            if (line.find(field)!= string::npos) {
                tempFile << field << ": " << value << endl;
                fieldFound = true;
            }
            else {
                tempFile << line << '\n';
            }
        }
        inputFile.close();
        tempFile.close();
        remove(dataFilePath);
        rename(dataTempFilePath, dataFilePath);
        if (!fieldFound) {
            cout << "Field not found." << '\n';
        }
    }
    else {
        cout << "Error opening the data file." << '\n';
    }
}