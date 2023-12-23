#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

extern string language;

// Настройки
void settings() {
    int a;
    string b;
    int c;
    int d;

    cout << "What do you want to customize?\n1 - Profile\n2 - Language\n3 - Console Color\n";
    cout << "Enter: ";
    cin >> a;

    if (a == 1) {
        cout << "New username: ";
        string new_username;
        cin >> ws;

        getline(cin, new_username);

        EditData("UserName", new_username);
        ReadData();
    } 
    else if (a == 2) {
        cout << "RU - Russian\nEN - English\n";
        cout << "Enter: ";
        cin >> b;

        if (b == "RU") {
            EditData("Language", "Russian");
            cout << "----------------------------------------------------------" << endl;
        } 
        else if (b == "EN") {
            EditData("Language", "English");
            cout << "----------------------------------------------------------" << endl;
        }
        ReadData();
    } 
    else if (a == 3) {
        cout << "[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
        cout << "Type in (Console Color): ";
        cin >> c;
        cout << "Type in (Text Color): ";
        cin >> d;

        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            string colorCode = "color " + to_string(c) + to_string(d);
            string colormoment(to_string(c) + to_string(d));
            system(colorCode.c_str());
            EditData("ColorsConsole", colormoment);
            cout << "----------------------------------------------------------" << endl;
        }
    } 
    else if (a == 4) {
        cout << "ТЫ ЧТО СМОТРИШЬ?! " << endl;
        cout << "----------------------------------------------------------" << endl;
    }
}