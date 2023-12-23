#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "data.h"
#include "error.h"

extern string language;

using namespace std;

/* 
* true - в конце сообщение будет "\n" (endl); false - не будет
* messageEn - сообщение на английском
* messageRu - сообщение на русском
* Пример: print(true, "Hello world!", "Привет мир!");
*/
void printMessage(const bool what, const string& messageEn, const string& messageRu) {
    if (language == "Russian" && what == true) {
        cout << messageRu << endl;
    }
    else if (language == "English" && what == true) {
        cout << messageEn << endl;
    }
    else if (language == "Russian" && what == false) {
        cout << messageRu;
    }
    else if (language == "English" && what == false) {
        cout << messageEn;
    }
    if (language.empty() || what == NULL || language.empty() && what == NULL) {
        
    }
}

void LogMessage(bool Done, string Message, int ErrorCode) {
    if (Done == true) {
        
    }
    else if (Done == false) {

    }
    else {

    }
}

// [Фэйковая загрузка]
void fakeLoading(const vector<string>& symbols, string MessageOne, string MessageTwo, string MessageThree, string Message4, string GreatBruh) {
    int index = 0; // index
    for (int i = 0; i < 3; i++) {
        cout << MessageOne << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        cout << MessageTwo << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        cout << MessageThree << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        cout << Message4 << " " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false;
    if (errorCondition) {
        cout << "SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << '\n';
    }
    else {
        cout << GreatBruh << endl;
    }
};