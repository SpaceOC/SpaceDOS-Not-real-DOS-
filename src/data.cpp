#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>
#include "other.h"

using namespace std;
using namespace filesystem;

string version = "1.6 Alpha"; // Версия SpaceDOS

map<string, string> User_Settings; // Язык, Username, Пароль, Дебаг моде

bool Password = false;

path dataFilePath = "Data/data.data"; // Путь для файла с данными
path logFilePath = "Data/logs.data"; // Путь для файла с логами (Начинает работать, если включить дебаг моде)
path dataTempFilePath = "Data/tempData.data"; // Путь для временного файла с новыми данными

void CreateFolders() {
    create_directory("Addons"); // Создание папки Addons (Боже зачем я всё комментирую xD)

    create_directory("Data");
    create_directory("Data/Games");

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
    if (!file && User_Settings["Debug Mode"] == "true") {
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

// Создания базового файла с данными для SpaceDOS
void CreateDataFile() {
    ifstream file(dataFilePath);
    if (!file) {
        ofstream data(dataFilePath);
        if (data) {
            data << "Language: English" << '\n';
            data << "UserName: unknown" << '\n';
            data << "Version: " << version << '\n';
            data << "Debug Mode: false" << '\n';
            data << "Password: " << '\n';
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

// Создания другого файла с данными
void CreateDataFile(path FilePath, vector<string> VarNames , vector<string> VarVar) {
    ifstream file(FilePath);
    if ((VarNames.empty() && VarVar.empty()) || VarNames.empty() || VarVar.empty()) {
        //cout << "А ПЕРЕМЕННЫЕ ГДЕ?!" << endl;
        VarNames.push_back("Lol");
        VarVar.push_back("Lol2");
    }
    else if (!file) {
        ofstream data(FilePath);
        if (data) {
            int i = 0;
            while (i <= (VarNames.size() - 1) && i <= (VarVar.size() - 1)) {
                cout << to_string(i);
                data << VarNames[i] + ": " + VarVar[i] << '\n';
                i++;
            }
            cout << to_string(VarNames.size()) << to_string(VarVar.size()) << endl;
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

// Прочитывание стандартных данных по пути Data/data.data
void ReadDataFile() {
    ifstream data(dataFilePath);
    if (data) {
        string line;
        bool foundLanguage = false;
        bool foundUsername = false;
        bool foundVersion = false;
        bool foundDebug_Mode = false;
        bool foundPassword = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find("Language: ") != string::npos) {
                User_Settings["language"] = line.substr(10);
                foundLanguage = true;
                LogMessage("DONE", {"SpaceDOS language at the moment: " + User_Settings["language"], "Язык SpaceDOS на данный момент - " + User_Settings["language"]}, 000);
            }
            if (!foundUsername && line.find("UserName: ") != string::npos) {
                User_Settings["username"] = line.substr(10);
                foundUsername = true;
                LogMessage("DONE", {"The user's current nickname: " + User_Settings["username"], "Текущий никнейм пользователя - " + User_Settings["username"]}, 000);
            }
            if (!foundDebug_Mode && line.find("Debug Mode: ") != string::npos) {
                User_Settings["Debug Mode"] = line.substr(12);
                foundDebug_Mode = true;
            }
            if (!Password && line.find("Password: ") != string::npos) {
                User_Settings["Password"] = line.substr(10);
                if (User_Settings["Password"].empty()) {
                    Password = false;
                }
                else {
                    Password = true;
                }
                foundPassword = true;
            }
            if (foundLanguage && foundUsername && foundVersion && foundDebug_Mode && foundPassword) {
                LogMessage("INFO", {"All data found: username, language, password and debug mode", "Все данные найдены: имя пользователя, язык, пароль и режим отладки"}, 000);
                break;
            }
        }
        data.close();
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
    }
}

// Прочитывание и получение одного значения переменной в файле с данными по пути Data/data.data
void ReadDataFile(string VarName, string& GetVar) {
    ifstream data(dataFilePath);
    if (data) {
        string line;
        bool foundVar = false;
        while (getline(data, line)) {
            if (!foundVar && line.find(VarName + ": ") != string::npos) {
                GetVar = line.substr(VarName.size() + 2);
                foundVar = true;
                LogMessage("DONE", {"The value of the variable ( " + VarName + " ) is: " + GetVar, "Значение переменной ( " + VarName + " ) равняется: " + GetVar}, 000);
            }
            if (foundVar) {
                LogMessage("INFO", {"All data found: username, language and debug mode", "Данная переменная, " + VarName + " , найдена"}, 000);
                break;
            }
        }
        data.close();
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
    }
}

// Прочитывание и получение одного переменного в файле с данными
void ReadDataFile(string VarName, string& GetVar, path FilePath) {
    ifstream data(FilePath);
    if (data) {
        string line;
        bool foundVar = false;
        while (getline(data, line)) {
            if (!foundVar && line.find(VarName + ": ") != string::npos) {
                GetVar = line.substr(VarName.size() + 2);
                foundVar = true;
                LogMessage("DONE", {"The value of the variable ( " + VarName + " ) is: " + GetVar, "Значение переменной ( " + VarName + " ) равняется: " + GetVar}, 000);
            }
            if (foundVar) {
                LogMessage("INFO", {"All data found: username, language and debug mode", "Данная переменная, " + VarName + " , найдена"}, 000);
                break;
            }
        }
        data.close();
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
    }
}

// Функция изменения стандартных данных в файле с данными по пути Data/data.data
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

// Функция изменения стандартных данных в файле с данными по пути {путь указываете сами}
void EditData(const string& field, const string& value, const path FilePath, const path TempFilePath) {
    ifstream inputFile(FilePath);
    ofstream tempFile(TempFilePath);
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
        remove(FilePath);
        rename(TempFilePath, FilePath);
        if (!fieldFound) {
            LogMessage("ERROR", {"Field not found", "Поле не найдено"}, 000);
        }
    }
    else {
        LogMessage("ERROR", {"Error opening the data file", "Ошибка при открытии файла данных"}, 000);
    }
}