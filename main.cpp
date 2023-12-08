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
#include "zmeika.h"

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

int main(){
    setlocale(LC_ALL, "");

    vector<wstring> allowedCommands = {
        L"help", L"logo", L"calculator", L"version", L"exit", 
        L"delete", L"hi", L"say", L"RSP", L"settings", 
        L"counter", L"time", L"zmeika"
    };

    CreateData();
    ReadData();

    fakeLoading();

    Sleep(2000);

    printMessage(L"yes", L"Welcome to SpaceDOS!", L"Добро пожаловать в SpaceDOS!");
    wcout << L"Version SpaceDOS - [ " << version << L" ]" << L'\n';

    PrintTimeMonth();

    while (true){
        wstring command_input;
        

        if(language == L"Russian"){
            wcout << L"Введите команду: ";
        }
        else{
            wcout << L"Enter command: ";
        }
        wcin >> command_input;

        if(command_input == L"delete"){
            FUNdelete();
        }

        if (command_input == L"time") {
            calculateWorkTime();
        }

        if (command_input == L"zmeika") {
            Start();
        }

        if(command_input == L"exit"){
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