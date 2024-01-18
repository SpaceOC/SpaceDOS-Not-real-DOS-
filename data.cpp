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

string version = "1.4 Alpha"; // Версия SpaceDOS

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
    //string path = "Addons/AddonsList.json";
    path path = "Addons/AddonsList.txt";
    if (exists(path)) {
        LogMessage("INFO", {"The file \"AddonsList.txt\" was found.", "Файл \"AddonsList.txt\" найден"}, 000); // М-да.... Ничего путного я пока что не придумал для LogMessage 💀💀💀

        
    } 
    else {
        LogMessage("ERROR", {"The file \"AddonsList.txt\" was not found.", "Файл \"AddonsList.txt\" не найден"}, 404);

        ifstream file(path);
        if (!file) {
            ofstream data(path);
            if (data) {
                data.close();
            }
            else {
                LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла AddonsList.txt"}, 000);
            }
        }
        else {
            file.close();
        }
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
            LogMessage("ERROR", {"Error opening log file", "Ошибка в открытии лог файла"}, 000);
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
            LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
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
                foundLanguage = true;
                LogMessage("DONE", {"SpaceDOS language at the moment: " + language, "Язык SpaceDOS на данный момент - " + language}, 000);
            }
            if (!foundUsername && line.find("UserName: ") != string::npos) {
                username = line.substr(10);
                cout << "Username: " << username << '\n';
                foundUsername = true;
                LogMessage("DONE", {"The user's current nickname: " + username, "Текущий никнейм пользователя - " + username}, 000);
            }
            if (!foundVersion && line.find("Version: ") != string::npos) {
                RealVersion = line.substr(9);
                cout << "Version: " << RealVersion << '\n';
                foundVersion = true;
                LogMessage("DONE", {"The current version of SpaceDOS: " + version, "Текущая версия SpaceDOS - " + version}, 000);
            }
            if (!foundDebug_Mode && line.find("Debug Mode: ") != string::npos) {
                Debug_Mode = line.substr(12);
                cout << "Debug Mode: " << Debug_Mode << '\n';
                foundDebug_Mode = true;
            }
            if (foundLanguage && foundUsername && foundVersion && foundDebug_Mode) {
                LogMessage("INFO", {"All data found: version, user name, language and debug mode", "Все данные найдены: версия, имя пользователя, язык и режим отладки"}, 000);
                break;
            }
        }
        data.close();
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
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
            LogMessage("ERROR", {"Field not found", "Поле не найдено"}, 000);
        }
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
    }
}