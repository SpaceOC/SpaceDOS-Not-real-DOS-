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

void StartOOBE() {
    vector<wstring> symbolsOOBE = {
        L"|", L"/", L"-", L"\\"
    };

    fakeLoading(symbolsOOBE, 0, L"Loading", L"Loading Data", L"Loading User", L"...", L"OOBE!!!");

    wcout << L"Давай я помогу тебе настроить SpaceDOS!" << endl;
    wcout << L"1 or \"start\" - Начать..." << endl << L"2 or \"skip\" - Пропустить..." << endl;

    OOBE_moment:
    wstring OOBE_start;
    wcin >> ws;

    getline(wcin, OOBE_start);

    if (OOBE_start == L"1" || OOBE_start == L"start") {
        wcout << L"Хорошо!" << endl;
        wcout << L"Ваш никнейм: ";
        wstring Your_Username;
        wcin >> ws;
        getline(wcin, Your_Username);
        EditData(L"UserName", Your_Username);

        wcout << L"Хорошо... Ваш username \"" << Your_Username << L"\"" << endl << L"Дальше!" << endl; 
        wcout << L"Ваш язык (Вы можете выбрать только English или Russian пока что): ";
        wstring Your_Language;
        wcin >> ws;
        getline(wcin, Your_Language);
        EditData(L"Language", Your_Language);

        wcout << L"Хорошо, а теперь цвет консоли (первая цифра (только от 0 до 9) - Сам цвет консоли, вторая цифра (только от 0 до 9) - цвет текста): ";
        wstring Your_ConsoleColor;
        wcin >> ws;
        getline(wcin, Your_ConsoleColor);
        EditData(L"ColorsConsole", Your_ConsoleColor);

        wcout << L"Теперь вы готовы использовать SpaceDOS..." << endl;
        EditData(L"Verifed Of OBBE", L"true");
        ReadData();
    }
    if (OOBE_start == L"2" || OOBE_start == L"skip") {
        EditData(L"Verifed Of OBBE", L"true");
        ReadData();
    }
    if (!(OOBE_start == L"2" || OOBE_start == L"skip") && !(OOBE_start == L"1" || OOBE_start == L"start")) {
        cout << "Я вас не понял, извините. Повторите попытку" << endl;
        goto OOBE_moment;
    }
}