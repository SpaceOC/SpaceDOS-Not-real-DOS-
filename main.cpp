// Даже не спрашивайте почему тут так много библиотек (или как там их называть)....
#include <iostream>
#include <windows.h>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include "Commands/Main_Commands.h"
#include "Games/Main_Games.h"
#include "data.h"
#include "time.h"
#include "counters.h"
#include "other.h"
#include "OOBE.h"

// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!


// Если вы получили код не с гит хаба или вообще не читали readme там, то я оставил его здесь :/
/*
# C++
- Я его только начал изучать. Я не всё выучил. Я добавляю в SpaceDOS то, что мне нужно закрепить после изучения определённого урока или то, что нужно для SpaceDOS по моему мнению.

# Что за SpaceDOS [Not real DOS]
- Проект, который делается в соло
- Мой первый проект на C++ (не судите строго, пожалуйста)
- Проект для закрепа моих знаний по C++

# Зачем сделал? В чём идея?
- Изначально, чисто по приколу. Через какое-то время начал подумывать, что SpaceDOS - одно большое приложение с большим кол-во консольных игр будет. К примеру `Камень, ножницы, бумага` или `Змейка` (которая была удалена в 1.0 Alpha). Потом начал думать о том, что это будет полезное приложения для быстрого решения задач. Например квадратное уравнение... Я пока что не выбрал... Через какое-то время я опять подумал, что в SpaceDOS будет консольный движок для консольных игр 💀💀💀💀💀.... Возможно, будет всё сразу... А может и нет `¯\_(ツ)_/¯`.

# Версия SpaceDOS?
- 1.0 Alpha

# Что там есть?
- OOBE на минималках
- команды `help, say, clear, counter, hi, delete, notepad и ещё другие`
- Русский (??%) и Английский (??%)
- Настройки на минималках

# Твой код ужасен. ПЕРЕДЕЛЫВАЙ!
- Ну а как без этого. Я же сказал, что только начал изучать C++

# Как cкомпилировать твой код?
- Иметь прямые руки разумеется!
- MinGW

### А как установить MinGW?
- https://semicolon.dev/windows/how-to-install-mingw-gcc-g-compiler-windows-10-11-2023 (Для Windows + на английском. Русскую версию не нашёл, простите)
- https://onstartup.ru/razrabotka/mingw-w64/?ysclid=lq51y8zpjr464479408 (Для Ubuntu + на русском)

### После того, как установлен MinGW
- Откройте командную строку (Если на Windows. Как сделать это всё на линуксе? Я не знаю :(. Я плохо разбираюсь там + только сам недавно начал пользоваться линуксом... Arch 💀👍. Через сто лет попробую Ubunty)
- Перейдите в директорию с исходным кодом SpaceDOS, используя команду cd 💀💀💀💀. Например: `cd C:\путь\к\вашей\директории\c\исходным\кодом\SpaceDOS`
- В командную строку напишите `mingw32-make`.
- Если всё пройдет успешно, то у вас должен появиться файл под названием `SpaceDOS.exe`
*/

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
        "delete", "hi", "say", "RSP", "settings", 
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

        if(command_input == "delete"){
            FUNdelete();
        }

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

        if(command_input == "say"){
            say();
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

        if(command_input == "RSP"){ // Rock, Scissors, Paper // Да.. Я не знаю как по другому написать. У меня не работает просто, если напишу Rock, Scissors, Paper вместо "RSP"
            RSP();
        }

        if (command_input == "logo"){ // Не работает :(
            logo();
        }

        if (command_input == "notepad") {
            notepad();
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

    if (VerifedOOBE == "false" || VerifedOOBE == "0") {
        StartOOBE();
    }
    if (VerifedOOBE == "unknown") {
        while (VerifedOOBE == "false" || VerifedOOBE == "unknown") {
            cout << "При проверке произошла ошибка из-за которой вы видите данный текст. Настоятельно рекомендуем заново пройти OOBE, чтобы SpaceDOS не сломался во время работы." << endl << "1 or OK - Запустить OOBE" << endl << "2 or SKIP - Дальше использовать SpaceDOS (КРАЙНЕ НЕ РЕКОМЕНДУЕТСЯ)" << endl << "Введите: ";
            string wtf_moment;
            cin >> ws;
            getline(cin, wtf_moment);

            if (wtf_moment == "1" || wtf_moment == "OK" || wtf_moment == "Ok" || wtf_moment == "OK" || wtf_moment == "Oк") {
                StartOOBE();
                break;
            }
            if (wtf_moment == "2" || wtf_moment == "SKIP" || wtf_moment == "Skip") {
                DOS();
                break;
            }
            else {
                cout << "Вы ввели неправильно. Повторите: ";
            }
        }
    }
    if (VerifedOOBE == "true") {
        DOS();
    }

}
