#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

wstring version = L"1.0 Alpha";

wstring DefaultLanguage = L"English";
wstring DefaultUserName = L"defaultuser0";
wstring Default_ColorsConsole = L"07";
bool Default_VerifedOfOOBE = false;

wstring ColorsConsole;
wstring VerifedOOBE;
wstring language;
wstring username;

void CreateData() {
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
        if (data) {
            data << L"Language: " << DefaultLanguage << L'\n';
            data << L"UserName: " << DefaultUserName << L'\n';
            data << L"Verifed Of OBBE: " << Default_VerifedOfOOBE << L'\n';
            data << L"ColorsConsole: " << Default_ColorsConsole << L'\n';
            data.close();
        }
        else {
            wcout << L"Error opening the data file." << L'\n';
        }
    }
    else {
        file.close();
    }
}

void ReadData() {
    wifstream data("data.data");
    if (data) {
        wstring line;
        bool foundLanguage = false;
        bool foundUsername = false;
        bool foundOOBE = false;
        bool foundColorsConsole = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find(L"Language: ") != wstring::npos) {
                language = line.substr(10);
                wcout << L"Language: " << language << L'\n';
                foundLanguage = true;
            }
            if (!foundUsername && line.find(L"UserName: ") != wstring::npos) {
                username = line.substr(10);
                wcout << L"Username: " << username << L'\n';
                foundUsername = true;
            }
            if (!foundOOBE && line.find(L"Verifed Of OBBE: ") != wstring::npos) {
                VerifedOOBE = line.substr(17);
                if (VerifedOOBE == L"0" || VerifedOOBE == L"false") {
                    VerifedOOBE = L"false";
                }
                if (VerifedOOBE == L"1" || VerifedOOBE == L"true") {
                    VerifedOOBE = L"true";
                }
                else {
                    cerr << "Error: Unknown variable" << endl;
                    VerifedOOBE = L"unknown";
                }
                wcout << L"Verifed of OOBE: " << VerifedOOBE << L'\n';
                foundOOBE = true;
            }
            if (!foundColorsConsole && line.find(L"ColorsConsole: ") != wstring::npos) {
                ColorsConsole = line.substr(15);
                if (ColorsConsole.find_first_not_of(L"0123456789")!= wstring::npos) {
                    cerr << "Error: Invalid characters in input" << endl;
                    system("color 07");
                }
                else {
                    try {
                        int ColorsBlyat = stoi(ColorsConsole);
                        string colorCodeConsole = "color " + to_string(ColorsBlyat);
                        system(colorCodeConsole.c_str());
                        wcout << L"ColorsConsole: " << ColorsBlyat << L'\n';
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
        wcout << L"Error opening the data file." << std::endl;
    }
}

void EditData(const wstring& field, const wstring& value) {
    wifstream inputFile("data.data");
    wofstream tempFile("temp.data");
    if (inputFile && tempFile) {
        wstring line;
        bool fieldFound = false;
        while (getline(inputFile, line)) {
            if (line.find(field) != wstring::npos) {
                tempFile << field << L": " << value << L'\n';
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
            wcout << L"Field not found." << L'\n';
        }
    }
    else {
        wcout << L"Error opening the data file." << L'\n';
    }
}