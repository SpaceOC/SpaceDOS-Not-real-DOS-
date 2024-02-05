// Не получилось совершить задуманное... Опять все команды (help, version и т.д) в одном файле будут... 💀👍
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <type_traits>
#include "data.h"
#include "other.h"

using namespace std;

extern string language;
extern string version;

string description;

// команда help - показывает все команды
void help(string commandMoment) {
    vector<string> CommandsTextHelp_RU = { // Команды и их описание на русском
        " exit         \t Выйти из SpaceDOS",
        " help         \t Показывает все доступные команды",
        " settings     \t Настройки",
        " version      \t Показывает версию этой \"игры\"",
        " hi           \t Привет!", 
        " RSP          \t Сыграй в \"Камень, Ножницы, Бумага\"!",
        " work_time    \t Показывает сколько времени работает SpaceDOS [Not Real DOS]",
        " counter      \t Описание отсутствует", 
        " clear        \t Очистить командную строку",
        " logo         \t Показать лого SpaceDOS",
        " source code  \t Source code SpaceDOS"
    };

    vector<string> CommandsTextHelp_EN = { // Команды и их описание на английском
        " exit         \t Exit SpaceDOS",
        " help         \t Shows all available commands",
        " settings     \t SpaceDOS settings",
        " version      \t Shows the version of this \"game\"",
        " hi           \t Hi!", 
        " RSP          \t Play \"Rock, Paper, Scissors\"!",
        " work_time    \t Shows how long SpaceDOS has been running",
        " counter      \t No description", 
        " clear        \t Clear the command line",
        " logo         \t Show SpaceDOS logo",
        " source code  \t Source code SpaceDOS"
    };
    if (commandMoment.empty() and language == "Russian") {
        for (const auto& command : CommandsTextHelp_RU) {
            cout << command << endl;
        }
        LogMessage("DONE", {"The \"help\" command displayed the entire list of commands (in Russian) successfully", "Команда \"help\" вывела весь список команд (на русском языке) успешно"}, 000);
    }
    else if (commandMoment.empty() and language == "English") {
        for (const auto& command : CommandsTextHelp_EN) {
            cout << command << endl;
        }
        LogMessage("DONE", {"The \"help\" command displayed the entire list of commands (in English) successfully", "Команда \"help\" вывела весь список команд (на английском языке) успешно"}, 000);
    }
    else {
        if (language == "Russian") {
            for (const auto& command : CommandsTextHelp_RU) {
                if (command.find(commandMoment)!= string::npos) {
                    cout << command << endl;
                    LogMessage("DONE", {"The \"help\" command outputs \"" + command + "\" (in Russian) successfully", "Команда \"help\" вывела \"" + command + "\" (на русском языке) успешно"}, 000);
                }
            }
        }
        else {
            for (const auto& command : CommandsTextHelp_EN) {
                if (command.find(commandMoment)!= string::npos) {
                    cout << command << endl;
                    LogMessage("DONE", {"The \"help\" command outputs \"" + command + "\" (in English) successfully", "Команда \"help\" вывела \"" + command + "\" (на английском языке) успешно"}, 000);
                }
            }
        }
    }
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"The \"help\" command has been completed successfully.", "Работа команды \"help\" завершена успешно"}, 000);
}

// Настройки
void settings() {
    // Я не придумал ничего лучше чем заменить int на string.......
    int a; // Переменная для выбора пользователем | Я устал.... 💀👍
    string b; // Доп. переменная
    int c; // Доп. переменная
    int d; // Доп. переменная

    cout << "What do you want to customize? \n\t1 - Profile\n\t2 - Language\n\t3 - Console Color\n\t4 - Debug Mode\n";
    printMessage(false, {"Enter: ", "Введите: "});
    
    while(!(cin >> a))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        printMessage(false, {"Enter: ", "Введите: "});
    } 

    if (a == 1) {
        printMessage(false, {"New username: ", "Новое имя пользователя: "});
        string new_username;
        cin >> new_username;
        cout << "----------------------------------------------------------" << endl;

        /*getline(cin, new_username);*/

        EditData("UserName", new_username);
        ReadDataFile();
        cout << "----------------------------------------------------------" << endl;
    } 
    else if (a == 2) {
        cout << "RU - Russian\nEN - English\n";
        printMessage(false, {"Enter: ", "Введите: "});
        cin >> b;

        if (b == "RU") {
            EditData("Language", "Russian");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"Language changed to Russian", "Язык сменён на русский"}, 000);
        } 
        else if (b == "EN") {
            EditData("Language", "English");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"The language has been changed to English", "Язык сменён на английский"}, 000);
        }
        ReadDataFile();
        cout << "----------------------------------------------------------" << endl;
    } 
    else if (a == 3) {
        cout << "[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
        printMessage(false, {"Type in (Console Color): ", "Введите (Console Color): "});

        while(!(cin >> c))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            printMessage(false, {"Type in (Console Color): ", "Введите (Console Color): "});
        } 

        printMessage(false, {"Type in (Text Color): ", "Введите (Text Color): "});

        while(!(cin >> d))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            printMessage(false, {"Type in (Text Color): ", "Введите (Text Color): "});
        } 

        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            string colorCode = "color " + to_string(c) + to_string(d);
            system(colorCode.c_str());
            EditData("ColorsConsole", to_string(c) + to_string(d));
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"The color of the line command has been changed. Here's the code: " + to_string(c) + to_string(d), "Цвет командой строки изменён. Вот код: " + to_string(c) + to_string(d)}, 000);
        }
    } 
    else if (a == 4) {
        cout << "True/ON | False/OFF" << endl;
        printMessage(false, {"Enter: ", "Введите: "});
        cin >> b;

        if (b == "True" || b == "ON") {
            EditData("Debug Mode", "true");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"Debug Mode enabled", "Debug Mode включен"}, 000);
        } 
        else if (b == "False" || b == "OFF") {
            LogMessage("DONE", {"Debug Mode is disabled", "Debug Mode выключен"}, 000);
            EditData("Debug Mode", "false");
            cout << "----------------------------------------------------------" << endl;
        }
        ReadDataFile();
        cout << "----------------------------------------------------------" << endl;
    }
}

// 🥶👍
void hi() {
    vector<string> Hello_EN = {
        "Hi!",
        "Hello!",
        "Hi there!",
        "Howdy!"
    };
    vector<string> Hello_RU = {
        "Привет!",
        "Здравствуйте.",
        "Здарова.",
        "Приветствую."
    };

    int a = rand() % 4;

    printMessage(true, {Hello_EN[a], Hello_RU[a]});
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"Command \"hi\" has successfully completed its work", "Команда \"hi\" успешно завершила свою работу"}, 000);
}

// version
void DOSVersion() {
    cout << "SpaceDOS " << "[ " << version << " ]" << '\n';
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"A SpaceDOS version message was successfully sent using the \"version\" command", "Успешно было отправлено сообщение о версии SpaceDOS с помощью команды \"version\""}, 000);
}

// Лого
void logo() {
    vector<string> vs
    {
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣤⣤⣤)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣟⢛⠛⢛⣉⣤⣉⡀⢸⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⡿⠋⠁⠀⠈⢷⣄⠈⢿⣿⣿⡇⣼⣿⡿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠙⢷⣤⡈⠻⢧⣿⣿⠇)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⡀⢀⡀⠀⠀⠀⠀⠙⢿⣇⣼⣿⡟⠀)",
        R"(⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣶⣿⣿⠿⠁⠀⠀⢀⠂⠀⠀⠀⠪⢂⠀⠀⠀⠀⠀⣸⣿⣿⠁⠀)",
        R"(⠀⠀⠀⣠⣾⣿⡿⠋⠉⠭⠭⠭⢭⠟⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⣰⣿⡿⠁⠀⠀)",
        R"(⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠣⠄⠀⠀⠀⠀⠀⠀⢠⣾⣿⡿⠁⠀⠀⠀)",
        R"(⠀⠙⢿⣿⣷⣄⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠏⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠙⢿⣿⣷⣞⠁⠀⠀⠀⠀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠀⣼⣿⡿⠘⠳⣄⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⢠⣿⣿⠃⠀⠀⠈⠳⣤⣾⠟⠁⠀⠀⠀⠀⠀⢀⠔⢹⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⣠⣿⣿⠟⢦⡀⠀⠀⠀⠘⠳⣄⠀⠀⠀⠀⢀⠔⠁⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⢰⣿⣿⠁⢰⠃⠙⢦⡀⠀⠀⠀⠘⠷⡀⢀⡔⠁⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⣿⣿⡇⠀⡇⠀⠀⡀⠙⢦⢀⣀⣠⣴⣾⣧⡁⠀⠀⠀⢠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢰⣿⣿⠀⠘⠁⠒⠈⣀⣴⣾⣿⣿⠿⠿⠿⣿⣿⣧⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢸⣿⣿⣤⣤⣵⣶⣿⣿⡿⠟⠉⠀⠀⠀⠀⠈⠻⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠘⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)"
    };
    for (auto s : vs)
        cout << s << "\n";
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"The SpaceDOS logo has been successfully sent", "Логотип SpaceDOS успешно отправлен"}, 000);
}