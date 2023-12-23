#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string version = "1.1 Alpha"; // Версия SpaceDOS

string DefaultLanguage = "English"; // Стандартный язык в SpaceDOS
string DefaultUserName = "defaultuser0"; // Стандартное имя пользователя в SpaceDOS
string Default_ColorsConsole = "07"; // Стандартный цвет консоли и его текста в SpaceDOS
bool Default_VerifedOfOOBE = false; // Стандартное значение OOBE в SpaceDOS

string ColorsConsole;
string VerifedOOBE;
string language; // Язык (Не стандартный)
string username; // Username (Не стандартный)

// Создание базового файла для сохранения стандартных настроек - Language, Username, Verifed of OOBE и Colors Console
void CreateData() {
    ifstream file("data.data");
    if (!file) {
        ofstream data("data.data");
        if (data) {
            data << "Language: " << DefaultLanguage << '\n';
            data << "UserName: " << DefaultUserName << '\n';
            data << "Verifed Of OBBE: " << Default_VerifedOfOOBE << '\n';
            data << "ColorsConsole: " << Default_ColorsConsole << '\n';
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
void ReadData() {
    ifstream data("data.data");
    if (data) {
        string line;
        bool foundLanguage = false;
        bool foundUsername = false;
        bool foundOOBE = false;
        bool foundColorsConsole = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find("Language: ") != string::npos) {
                language = line.substr(10);
                cout << "Language: " << language << '\n';
                foundLanguage = true;
            }
            if (!foundUsername && line.find("UserName: ") != string::npos) {
                username = line.substr(10);
                cout << "Username: " << username << '\n';
                foundUsername = true;
            }
            if (!foundOOBE && line.find("Verifed Of OBBE: ") != string::npos) {
                VerifedOOBE = line.substr(17);
                if (VerifedOOBE == "0" || VerifedOOBE == "false") {
                    VerifedOOBE = "false";
                }
                else if (VerifedOOBE == "1" || VerifedOOBE == "true") {
                    VerifedOOBE = "true";
                }
                else {
                    cerr << "Error: Unknown variable" << endl;
                    VerifedOOBE = "unknown";
                }
                cout << "Verifed of OOBE: " << VerifedOOBE << '\n';
                foundOOBE = true;
            }
            if (!foundColorsConsole && line.find("ColorsConsole: ") != string::npos) {
                ColorsConsole = line.substr(15);
                if (ColorsConsole.find_first_not_of("0123456789")!= string::npos) {
                    cerr << "Error: Invalid characters in input" << endl;
                    system("color 07");
                }
                else {
                    try {
                        int ColorsBlyat = stoi(ColorsConsole);
                        string colorCodeConsole = "color " + to_string(ColorsBlyat);
                        system(colorCodeConsole.c_str());
                        cout << "ColorsConsole: " << ColorsBlyat << '\n';
                        foundColorsConsole = true;
                    }
                    catch (const std::invalid_argument& e) {
                        cerr << "Error occurred: " << e.what() << endl;
                        system("color 07");
                    }
                }
                /*
                int ColorsBlyat = stoi(ColorsConsole);
                string colorCodeConsole = "color " + to_string(ColorsBlyat);
                system(colorCodeConsole.c_str());
                wcout << L"ColorsConsole: " << ColorsBlyat << L'\n';
                foundColorsConsole = true;
                */
            }
            if (foundLanguage && foundUsername && foundOOBE && foundColorsConsole) {
                break;
            }
        }
        data.close();
    }
    else {
        cout << "Error opening the data file." << std::endl;
    }
}

// Функция изменения стандартных данных (Language, Username, Verifed of OOBE и Colors Console) в data.data
void EditData(const string& field, const string& value) {
    ifstream inputFile("data.data");
    ofstream tempFile("temp.data");
    if (inputFile && tempFile) {
        string line;
        bool fieldFound = false;
        while (getline(inputFile, line)) {
            if (line.find(field) != string::npos) {
                tempFile << field << ": " << value << '\n';
                fieldFound = true;
            }
            else {
                tempFile << line << L'\n';
            }
        }
        inputFile.close();
        tempFile.close();
        remove("data.data");
        rename("temp.data", "data.data");
        
        if (!fieldFound) {
            cout << "Field not found." << '\n';
        }
    }
    else {
        cout << "Error opening the data file." << '\n';
    }
}