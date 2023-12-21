// Даже не спрашивайте почему тут так много библиотек (или как там их называть)....
#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include "commands.h"
#include "data.h"
#include "time.h"
#include "counters.h"
#include "other.h"
#include "OOBE.h"

// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!



// Запасайтесь таблетками от кринжа и г###окодинга! Мы погружаемся в самый ужас!

using namespace std;

extern wstring version;
extern wstring DefaultLanguage;
extern wstring DefaultUserName;
extern wstring language;
extern wstring username;
extern wstring VerifedOOBE;

void DOS() {
    vector<wstring> allowedCommands = {
        L"help", L"logo", L"calculator", L"version", L"exit", 
        L"delete", L"hi", L"say", L"RSP", L"settings", 
        L"counter", L"time", L"clear"
    };

    printMessage(L"yes", L"Welcome to SpaceDOS!", L"Добро пожаловать в SpaceDOS!");
    wcout << L"Version SpaceDOS - [ " << version << L" ]" << L'\n';

    PrintTimeMonth();

    while (true){
        if(language == L"Russian"){
            wcout << L"Введите команду: ";
        }
        else{
            wcout << L"Enter command: ";
        }

        wstring command_input;
        wcin >> ws; // плов: ты провёл сто часов своей жизни чтобы понять, что эта строчка спасёт тебе жопу от wcin.ignore()

        getline(wcin, command_input);

        if(command_input == L"delete"){
            FUNdelete();
        }

        if (command_input == L"clear") {
            system("cls");
        }

        if (command_input == L"time") {
            calculateWorkTime();
        }

        if(command_input == L"exit"){
            system("color 07");
            
            break;
        }

        if(command_input == L"hi"){
            hi();
        }

        if(command_input == L"say"){
            say();
        }

        if(command_input == L"version"){
            DOSVersion();
        }

        if(command_input == L"counter"){
            counter();
        }

        if(command_input == L"help"){
            help();
        }

        if (find(allowedCommands.begin(), allowedCommands.end(), command_input) == allowedCommands.end()) {
            wcout << L"Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
            wcout << L"----------------------------------------------------------" << endl;
        }

        if (command_input == L"calculator") {
            calculator();
        }

        if(command_input == L"RSP"){ // Rock, Scissors, Paper // Да.. Я не знаю как по другому написать. У меня не работает просто, если напишу Rock, Scissors, Paper вместо "RSP"
            RSP();
        }

        if (command_input == L"logo"){ // Не работает :(
            logo();
        }

        if (command_input == L"notepad") {
            notepad();
        }

        if (command_input == L"settings") {
            settings();
        }
    }
}


int main(){
    setlocale(LC_ALL, "");

    CreateData();
    ReadData();

    vector<wstring> symbolsLoadingDOS = {
        L"|", L"/", L"-", L"\\"
    };
    fakeLoading(symbolsLoadingDOS, 0, L"Loading", L"Loading commands", L"Loading commands", L"Launching SpaceDOS", L"SpaceDOS launched successfully!");

    Sleep(2000);

    if (VerifedOOBE == L"false") {
        StartOOBE();
    }
    if (VerifedOOBE == L"unknown") {
        while (VerifedOOBE == L"false" || VerifedOOBE == L"unknown") {
            wcout << L"При проверке произошла ошибка из-за которой вы видите данный текст. Настоятельно рекомендуем заново пройти OOBE, чтобы SpaceDOS не сломался во время работы." << endl << L"1 or OK - Запустить OOBE" << endl << L"2 or SKIP - Дальше использовать SpaceDOS (КРАЙНЕ НЕ РЕКОМЕНДУЕТСЯ)" << endl << L"Введите: ";
            wstring wtf_moment;
            wcin >> ws;
            getline(wcin, wtf_moment);

            if (wtf_moment == L"1" || wtf_moment == L"OK" || wtf_moment == L"Ok" || wtf_moment == L"OK" || wtf_moment == L"Oк") {
                StartOOBE();
                break;
            }
            if (wtf_moment == L"2" || wtf_moment == L"SKIP" || wtf_moment == L"Skip") {
                break;
                DOS();
            }
            else {
                wcout << "Вы ввели неправильно. Повторите: ";
            }
        }
    }
    if (VerifedOOBE == L"true") {
        DOS();
    }

}
