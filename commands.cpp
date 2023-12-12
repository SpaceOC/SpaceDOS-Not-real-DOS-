#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <locale>
#include "data.h"
#include "other.h"

using namespace std;

bool LoadCommands = false;
extern wstring version;
extern wstring language;

// команда help - показывает все команды
void help() {
    wcout << L"exit - выйти из SpaceDOS" << endl << L"help - displays a list of all commands" << endl << L"settings - настройки" << endl << L"version - shows the version of this \"game\"" << endl << L"delete - removes user from Real Life (DANGER!)" << endl << L"hi - Hi!" << endl << L"calculator - Calculator" << endl << L"RSP - Rock, Scissors, Paper!" << endl << L"time - Work Time" << endl << L"counter - ..." << endl << L"clear - Очистить командную строку" << endl << L"say - say" << endl;
    wcout << L"----------------------------------------------------------" << endl;
}

// команда calculator - КАЛЬКУЛЯТОР НА МИНИМАЛКАХ
void calculator() {
    double Fnum;
    double Snum;
    char op;

    wcout << L"Enter the first number: ";
    wcin >> Fnum;
    wcout << L"Enter the operator (+, -, *, /): ";
    cin >> op;
    wcout << L"Enter the second number: ";
    wcin >> Snum;

    double result;
    switch (op) {
        case '+':
            result = Fnum + Snum;
            break;
        case '-':
            result = Fnum - Snum;
            break;
        case '*':
            result = Fnum * Snum;
            break;
        case '/':
            if (Snum != 0) {
                result = Fnum / Snum;
            } else {
                    wcout << L"Error: Cannot divide by zero!" << L'\n';
            }
            break;
        default:
            wcout << L"Error: Invalid operator!" << L'\n';
        }

    wcout << L"Done! The result is: " << result << L'\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// HI! Hello! Привет!!!
void hi() {
    wcout << L"Hi!" << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}

void FUNHacking() {
    printMessage(L"no", L"Enter: ", L"Введите username вашей жертвы: ");
    wstring bruh_username;

    wcin >> ws;

    getline(wcin, bruh_username);

    printMessage(L"no", L"Reason?: ", L"Причина?: ");
    wstring reason;
    wcin >> ws;

    getline(wcin, reason);

    
}

// Камень, ножницы, бумага!
void RSP() {
    int a;
    wcout << L"Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
    cin >> a;

    int v = rand() % 3 + 1;

    if (a == v) {
        wcout << "Tie!" << endl;
    }
    else if (a == 1 && v == 2) {
        wcout << "The rock breaks the scissors! The computer lost." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 3) {
        wcout << "The scissors cut the paper. The computer lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 1) {
        wcout << "The rock breaks the scissors! Player lost." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 2) {
        wcout << "The scissors cut the paper. The player has lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 1 && v == 3) {
        wcout << "Paper covers stone... The player has lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 1) {
        wcout << "Player wins! Paper covers rock" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else {
        wcout << L"Вы, возможно, написали неверное число или символы. Чтобы игра нормальна работала пишите только \"1\", \"2\" и \"3\"" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
}

// блокнот? 💀💀💀💀💀
void notepad() {
    string name_file;
    string data_text;
    string execute;
    string create;
    string tochka = ".";

    wcout << L"Создать файл или нужно изменить готовый? 1 - создать, 2 - изменить";
    cin >> create;
    wcout << L"Напиши имя файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, name_file);
    cin >> name_file;
    wcout << L"Что будет в этом файле? (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, data_text);
    cin >> data_text;
    wcout << L"Расширение файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, execute);
    cin >> execute;

    string fileName = name_file + tochka + execute;

    if (create == "1") {
        ofstream data(fileName);
        data << data_text << L'\n';
        data.close();
        wcout << L"----------------------------------------------------------" << endl;
    }
    else {
        wcout << L"Ничего ещё не готово. Уходите\n";
        wcout << L"----------------------------------------------------------" << endl;
    }
    /*
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
            if (data) {
                data << L"Language: " << DefaultLanguage << L'\n';
                data << L"UserName: " << DefaultUserName << L'\n';
                data.close();
            }
            else {
                wcout << L"Error opening\\create the data file." << L'\n';
            }
        }
        else {
            file.close();
    }
    */
}

// Настройки
void settings() {
    int a;
    wstring b;
    int c;
    int d;

    wcout << L"What do you want to customize?\n1 - Profile\n2 - Language\n3 - Console Color\n";
    wcout << L"Enter: ";
    cin >> a;

    if (a == 1) {
        wcout << L"New username: ";
        wstring new_username;
        wcin >> ws;

        getline(wcin, new_username);

        EditData(L"UserName", new_username);
        ReadData();
    } 
    else if (a == 2) {
        wcout << L"RU - Russian\nEN - English\n";
        wcout << L"Enter: ";
        wcin >> b;

        if (b == L"RU") {
            EditData(L"Language", L"Russian");
            wcout << L"----------------------------------------------------------" << endl;
        } 
        else if (b == L"EN") {
            EditData(L"Language", L"English");
            wcout << L"----------------------------------------------------------" << endl;
        }
        ReadData();
    } 
    else if (a == 3) {
        wcout << L"[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
        wcout << L"Type in (Console Color): ";
        cin >> c;
        wcout << L"Type in (Text Color): ";
        cin >> d;

        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            string colorCode = "color " + to_string(c) + to_string(d);
            wstring colormoment = to_wstring(c) + to_wstring(d);
            system(colorCode.c_str());
            EditData(L"ColorsConsole", colormoment);
            wcout << L"----------------------------------------------------------" << endl;
        }
    } 
    else if (a == 4) {
        wcout << L"ТЫ ЧТО СМОТРИШЬ?! " << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
}

// version
void DOSVersion() {
    wcout << L"SpaceDOS " << L"[ " << version << L" ]" << L'\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// Повторялка
void say() {
    printMessage(L"no", L"Enter text to say: ", L"Введите текст, который должен быть сказан: ");

    /*if (language == L"Russian") {
        wcout << L"Введите текст, который должен быть сказан: ";
    }
    else {
        wcout << L"Enter text to say: ";
    }*/

    wstring say_text;
    wcin >> ws;
    getline(wcin, say_text);

    wcout << say_text << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// Шуточное удаления пользователя из реал лайф
void FUNdelete() {
    printMessage(L"no", L"Write the username of the user you want to delete: ", L"Напишите username пользователя, которого вы хотите удалить: ");
    
    wstring d_user;
    wcin >> ws;
    getline(wcin, d_user);

    printMessage(L"no", L"The reason you want to delete the user?: ", L"Напишите причину удаления пользователя: ");
    
    wstring text;
    wcin >> ws;
    getline(wcin, text);

    if (language == L"Russian") {
        wcout << L"Начинаем процесс удаления юзера \"" << d_user << L"\"..." << L'\n';
    }
    else {
        wcout << L"Begin the process of deleting the user \"" << d_user << L"\"..." << L'\n';
    }

    Sleep(2000);

    printMessage(L"no", L"Enter text to say: ", L"Введите текст, который должен быть сказан: ");

    if (language == L"Russian") {
        wcout << L"Пользователь был успешно удалён по причине: \"" << text << L"\"" << L'\n';
    }
    else {
        wcout << L"The user was successfully deleted for a reason: \"" << text << L"\"" << L'\n';
    }
    wcout << L"----------------------------------------------------------" << endl;
}

// Не работает лого :(
void logo() {
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣤⣤⣤" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣟⢛⠛⢛⣉⣤⣉⡀⢸⣿⣿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⡿⠋⠁⠀⠈⢷⣄⠈⢿⣿⣿⡇⣼⣿⡿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠙⢷⣤⡈⠻⢧⣿⣿⠇" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⡀⢀⡀⠀⠀⠀⠀⠙⢿⣇⣼⣿⡟⠀" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣶⣿⣿⠿⠁⠀⠀⢀⠂⠀⠀⠀⠪⢂⠀⠀⠀⠀⠀⣸⣿⣿⠁⠀" << '\n';
    wcout << L"⠀⠀⠀⣠⣾⣿⡿⠋⠉⠭⠭⠭⢭⠟⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⣰⣿⡿⠁⠀⠀" << '\n';
    wcout << L"⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠣⠄⠀⠀⠀⠀⠀⠀⢠⣾⣿⡿⠁⠀⠀⠀" << '\n';
    wcout << L"⠀⠙⢿⣿⣷⣄⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠏⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⠙⢿⣿⣷⣞⠁⠀⠀⠀⠀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⠀⣼⣿⡿⠘⠳⣄⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⢠⣿⣿⠃⠀⠀⠈⠳⣤⣾⠟⠁⠀⠀⠀⠀⠀⢀⠔⢹⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⣠⣿⣿⠟⢦⡀⠀⠀⠀⠘⠳⣄⠀⠀⠀⠀⢀⠔⠁⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⢰⣿⣿⠁⢰⠃⠙⢦⡀⠀⠀⠀⠘⠷⡀⢀⡔⠁⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⣿⣿⡇⠀⡇⠀⠀⡀⠙⢦⢀⣀⣠⣴⣾⣧⡁⠀⠀⠀⢠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⢰⣿⣿⠀⠘⠁⠒⠈⣀⣴⣾⣿⣿⠿⠿⠿⣿⣿⣧⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⢸⣿⣿⣤⣤⣵⣶⣿⣿⡿⠟⠉⠀⠀⠀⠀⠈⠻⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠘⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}