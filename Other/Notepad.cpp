#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

// блокнот? 💀💀💀💀💀
// Блокнота не будет xD
void notepad() {
    string name_file;
    string data_text;
    string execute;
    string create;
    string tochka = ".";

    cout << "Создать файл или нужно изменить готовый? 1 - создать, 2 - изменить";
    cin >> create;
    cout << "Напиши имя файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, name_file);
    cin >> name_file;
    cout << "Что будет в этом файле? (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, data_text);
    cin >> data_text;
    cout << "Расширение файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, execute);
    cin >> execute;

    string fileName = name_file + tochka + execute;

    if (create == "1") {
        ofstream data(fileName);
        data << data_text << L'\n';
        data.close();
        cout << "----------------------------------------------------------" << endl;
    }
    else {
        cout << "Ничего ещё не готово. Уходите\n";
        cout << "----------------------------------------------------------" << endl;
    }
    /*
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
            if (data) {
                data << L"Language: " << DefaultLanguage << L'\n';
                data << L"UserName: " << DefaultUserName << L'\n';
                data.close();
            }
            else {
                wcout << L"Error opening\\create the data file." << L'\n';
            }
        }
        else {
            file.close();
    }
    */
}