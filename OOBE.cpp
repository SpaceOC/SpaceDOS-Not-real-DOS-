#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include "other.h"
#include "data.h"

using namespace std;

// OOBE
void StartOOBE() {
    cout << "Давай я помогу тебе настроить SpaceDOS!" << endl;

    cout << "Ваш никнейм: ";
    string Your_Username;
    cin >> ws;
    getline(cin, Your_Username);
    EditData("UserName", Your_Username);

    cout << "Хорошо... Ваш username \"" << Your_Username << "\"" << endl << "Дальше!" << endl; 
    cout << "Ваш язык (Вы можете выбрать только English или Russian пока что): ";
    string Your_Language;
    cin >> ws;
    getline(cin, Your_Language);
    EditData("Language", Your_Language);

    cout << "Хорошо, а теперь цвет консоли (первая цифра (только от 0 до 9) - Сам цвет консоли, вторая цифра (только от 0 до 9) - цвет текста): ";
    string Your_ConsoleColor;
    cin >> ws;
    getline(cin, Your_ConsoleColor);
    EditData("ColorsConsole", Your_ConsoleColor);

    cout << "Теперь вы готовы использовать SpaceDOS..." << endl;
    EditData("Verifed Of OBBE", "1");
    ReadData();
}