// Даже не спрашивайте почему тут так много библиотек (или как там их называть)....
#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
//#include "Other/Notepad.h"
#include "Games/Simple_Games/RSP.h"
#include "commands.h"
#include "data.h"
#include "time.h"
#include "counters.h"
#include "other.h"

// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!

using namespace std;

extern string version;
extern string DefaultLanguage;
extern string DefaultUserName;
extern string language;
extern string username;
extern string VerifedOOBE;

// DOS
void DOS() {
    vector<string> allowedCommands = { // Доступные команды
        "help", "logo", "calculator", "version", "exit", 
        "hi", "RSP", "settings", 
        "counter", "time", "clear"
    };

    printMessage(true, "Welcome to SpaceDOS!", "Добро пожаловать в SpaceDOS!");
    cout << "Version SpaceDOS - [ " << version << " ]" << '\n';

    PrintTimeMonth();

    while (true){
        if(language == "Russian"){
            cout << "Введите команду: ";
        }
        else{
            cout << "Enter command: ";
        }

        string command_input;
        cin >> ws; // плов: ты провёл сто часов своей жизни чтобы понять, что эта строчка спасёт тебе жопу от wcin.ignore()

        getline(cin, command_input);

        if (command_input == "clear") {
            system("cls");
        }

        if (command_input == "time") {
            calculateWorkTime();
        }

        if(command_input == "exit"){
            system("color 07");
            break;
        }

        if(command_input == "hi"){
            hi();
        }

        if(command_input == "version"){
            DOSVersion();
        }

        if(command_input == "counter"){
            counter();
        }

        if(command_input == "help"){
            help();
        }

        if (find(allowedCommands.begin(), allowedCommands.end(), command_input) == allowedCommands.end()) {
            cout << "Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
            cout << "----------------------------------------------------------" << endl;
        }

        if (command_input == "calculator") {
        }

        /*if(command_input == "RSP"){ // Rock, Scissors, Paper // Да.. Я не знаю как по другому написать. У меня не работает просто, если напишу Rock, Scissors, Paper вместо "RSP"
            RSP();
        }*/

        if (command_input == "logo"){ // Не работает :(
            logo();
        }

        if (command_input == "notepad") {
           // notepad();
        }

        if (command_input == "settings") {
            settings();
        }
    }
}


int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    CreateData();
    ReadData();

    vector<string> symbolsLoadingDOS = { // Символы фэйковой загрузки DOS
        "|", "/", "-", "\\"
    };
    fakeLoading(symbolsLoadingDOS, "Loading", "Loading commands", "Loading commands", "Launching SpaceDOS", "SpaceDOS launched successfully!");

    Sleep(100);

    DOS();
}