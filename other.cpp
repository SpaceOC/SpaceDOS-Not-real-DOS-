#include <iostream>
#include <windows.h>
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

void fakeLoading() {
    char symbols[] = {'|', '/', '-', '\\'};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        wcout << L"Loading " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        wcout << L"Loading commands " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        wcout << L"Loading commands " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        wcout << L"Launching SpaceDOS " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false;
    if (errorCondition) {
        wcout << L"SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << L'\n';
        wcout << L"error" << L'\n';
    }
    else {
        wcout << L"SpaceDOS launched successfully!" << L'\n';
    }
}