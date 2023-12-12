#include <iostream>
#include <windows.h>
#include <variant>
#include <string>
#include <vector>
#include "data.h"

extern wstring language;

using namespace std;

void printMessage(const wstring& what, const wstring& messageEn, const wstring& messageRu) {
    if (language == L"Russian" && what == L"yes") {
        wcout << messageRu << L'\n';
    }
    else if (language == L"English" && what == L"yes") {
        wcout << messageEn << L'\n';
    }
    else if (language == L"Russian" && what == L"no") {
        wcout << messageRu;
    }
    else if (language == L"English" && what == L"no") {
        wcout << messageEn;
    }
}

void fakeLoading(const vector<wstring>& symbols, int index, wstring MessageOne, wstring MessageTwo, wstring MessageThree, wstring Message4, wstring GreatBruh) {
    for (int i = 0; i < 3; i++) {
        wcout << MessageOne << L" " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        wcout << MessageTwo << L" " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        wcout << MessageThree << L" " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        wcout << Message4 << L" " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false;
    if (errorCondition) {
        wcout << L"SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << L'\n';
    }
    else {
        wcout << GreatBruh << L'\n';
    }
};