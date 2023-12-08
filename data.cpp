#include <iostream>
#include <fstream>

using namespace std;

wstring version = L"0.9 Alpha";
wstring DefaultLanguage = L"English";
wstring DefaultUserName = L"defaultuser0";
wstring language;
wstring username;

void CreateData() {
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
        if (data) {
            data << L"Language: " << DefaultLanguage << L'\n';
            data << L"UserName: " << DefaultUserName << L'\n';
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
        while (getline(data, line)) {
            if (!foundLanguage && line.find(L"Language: ") != wstring::npos) {
                language = line.substr(10);
                wcout << language << L'\n';
                foundLanguage = true;
            }
            if (!foundUsername && line.find(L"UserName: ") != wstring::npos) {
                username = line.substr(10);
                wcout << username << L'\n';
                foundUsername = true;
            }
            if (foundLanguage && foundUsername) {
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