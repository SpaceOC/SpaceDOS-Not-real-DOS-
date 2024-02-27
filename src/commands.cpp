// Не получилось совершить задуманное... Опять все команды (help, version и т.д) в одном файле будут... 💀👍
#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include "data.h"
#include "other.h"

using namespace std;

extern string version;
extern map<string, string> User_Settings;

string NameCommand;

// команда help - показывает все команды
void help(string commandMoment) {
    vector<string> CommandsTextHelp_RU = { // Команды и их описание на русском
        " exit         \t Выйти из SpaceDOS",
        " help         \t Показывает все доступные команды",
        " settings     \t Настройки",
        " version      \t Версия SpaceDOS",
        " hi           \t Привет!", 
        " RSP          \t Сыграй в \"Камень, Ножницы, Бумага\"!",
        " work_time    \t Показывает сколько времени работает SpaceDOS [Not Real DOS]",
        " counter      \t Описание отсутствует", 
        " clear        \t Очистить командную строку",
        " logo         \t Показать лого SpaceDOS",
        " source_code  \t Source code SpaceDOS",
        " tree         \t Дерево папок и файлов",
        " file [mode]  \t Действия с файлами",
        " search       \t Поиск файлов, папок",
        " create       \t Создание файла/файлов, папки/папок"
    };

    vector<string> CommandsTextHelp_EN = { // Команды и их описание на английском
        " exit         \t Exit SpaceDOS",
        " help         \t Shows all available commands",
        " settings     \t SpaceDOS settings",
        " version      \t SpaceDOS version",
        " hi           \t Hi!", 
        " RSP          \t Play \"Rock, Paper, Scissors\"!",
        " work_time    \t Shows how long SpaceDOS has been running",
        " counter      \t No description", 
        " clear        \t Clear the command line",
        " logo         \t Show SpaceDOS logo",
        " source_code  \t Source code SpaceDOS",
        " tree         \t No description",
        " file [mode]  \t No description",
        " search       \t No description",
        " create       \t No description"
    };
    if (commandMoment.empty() && User_Settings["language"] == "Russian") {
        for (const auto& command : CommandsTextHelp_RU) {
            cout << command << endl;
        }
        LogMessage("DONE", {"The \"help\" command displayed the entire list of commands (in Russian) successfully", "Команда \"help\" вывела весь список команд (на русском языке) успешно"}, 000);
    }
    else if (commandMoment.empty() && User_Settings["language"] == "English") {
        for (const auto& command : CommandsTextHelp_EN) {
            cout << command << endl;
        }
        LogMessage("DONE", {"The \"help\" command displayed the entire list of commands (in English) successfully", "Команда \"help\" вывела весь список команд (на английском языке) успешно"}, 000);
    }
    else {
        /*if (User_Settings["language"] == "Russian") {
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
        }*/
    }
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"The \"help\" command has been completed successfully.", "Работа команды \"help\" завершена успешно"}, 000);
}

// "Имба"
void CFile(string Type) {
    NameCommand = "File";
    string File_Name;
    cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
    cin >> File_Name;
    if (Type == "size") {
        size_t size = 0;
        fstream file(File_Name);
        file.seekg (0, std::ios::end);
        size = file.tellg();
        cout << "File size: " << size << " byte" << endl;
        file.close();
    }
    if (Type == "all") {
        cout << "Coming soon..." << endl; // ¯\_(ツ)_/¯
    }
}

// :skull:
void CCreate(string Type) {
    int i = 0;

    if (Type == "File") {
        string File_Name;
        cin >> File_Name;
        ifstream file(File_Name);
        if (!file) {
            ofstream data(File_Name);
            data.close();
        }
        else {
            file.close();
        }
    }
    if (Type == "Files") {
        vector<string> File_Name_List;
        string File_Name;
        
        while (true) {
            cin >> File_Name;
            if (File_Name != "SD_Done") {
                File_Name_List.push_back(File_Name);
            }
            else {
                break;
            }
        }
        while (i <= (File_Name_List.size() - 1)) {
            ifstream file(File_Name_List[i]);
            if (!file) {
                ofstream data(File_Name_List[i]);
                data.close();
            }
            else {
                file.close();
            }
            i++;
        }
    }
    if (Type == "Folder") {
        string Folder_Name;
        cin >> Folder_Name;

        create_directory(Folder_Name);
    }
    if (Type == "Folders") {
        string Temp_Folder_Name;
        vector<string> Folders_Name;

        int i = 0;
        printMessage(true, {"Enter a folder name (Enter \"SD_Done\" to finish entering folder names): ", "Введите название папок (Введите \"SD_Done\" чтобы закончить ввод названий папок): "});
        while (true) {
            cin >> Temp_Folder_Name;
            if (Temp_Folder_Name != "SD_Done") {
                Folders_Name.push_back(Temp_Folder_Name);
            }
            else {
                break;
            }
        }

        while (i <= (Folders_Name.size() - 1)) {
            create_directory(Folders_Name[i]);
            i++;
        }
    }
}

// Поиск файлов, папок :skull:
void search(string Type_Search) {
    int Count_Found = 0;
    if (Type_Search == "folder") {
        path Search_Var;
        cin >> Search_Var;
        auto status = filesystem::status(Search_Var);

        if (status.type() == file_type::directory) {
            cout << "Folder found >> " << Search_Var << " << Folder found" << endl;
        }
        else {
            cout << "Folder not found >> " << Search_Var << " << Folder not found" << endl;
        }
    }
    if (Type_Search == "file") {
        path Search_Var;
        cin >> Search_Var;
        auto status = filesystem::status(Search_Var);

        if (status.type() == file_type::regular) {
            cout << "File found >> " << Search_Var << " << File found" << endl;
        }
        else {
            cout << "File not found >> " << Search_Var << " << File not found" << endl;
        }
    }
    if (Type_Search == "folders") {
        vector<path> Search_Var;
        path Temp_Var_Check;
        int i = 0;
        printMessage(true, {"Enter (Enter \"SD_Done\" to start searching for folders): ", "Введите (Напишите \"SD_Done\" чтобы начать поиск папок): "});
        while (true) {
            cin >> Temp_Var_Check;
            if (Temp_Var_Check != "SD_Done") {
                Search_Var.push_back(Temp_Var_Check);
            }
            else {
                break;
            }
        }

        while (i <= Search_Var.size() - 1) {
            auto status = filesystem::status(Search_Var[i]);

            if (status.type() == file_type::directory) {
                cout << "Folder found >> " << Search_Var[i] << " << Folder found | Count i - " << i << endl;
            }
            else {
                cout << "Folder not found >> "  << Search_Var[i] << " << Folder not found | Count i - " << i << endl;
            }
            i++;
        }
    }
    if (Type_Search == "files") {
        vector<path> Search_Var;
        path Temp_Var_Check;
        int i = 0;
        printMessage(true, {"Enter files (Enter \"SD_Done\" to start searching for files): ", "Введите название файлов (Напишите \"SD_Done\" чтобы начать поиск файлов): "});
        while (true) {
            cin >> Temp_Var_Check;
            if (Temp_Var_Check != "SD_Done") {
                Search_Var.push_back(Temp_Var_Check);
            }
            else {
                break;
            }
        }

        while (i <= Search_Var.size() - 1) {
            auto status = filesystem::status(Search_Var[i]);

            if (status.type() == file_type::regular) {
                cout << "File found >> " << Search_Var[i] << " << File found | Count i - " << i << endl;
            }
            else {
                cout << "File not found >> "  << Search_Var[i] << " << File found | Count i - " << i << endl;
            }
            i++;
        }
    }
    if (Type_Search == "All") {
        vector<path> Search_Var;
        path Temp_Var_Check;
        int i = 0;
        printMessage(false, {"Enter files: ", "Введите название файлов/папок (или их пути) (Напишите \"SD_Done\" чтобы начать поиск файлов/папок): "});
        while (true) {
            cin >> Temp_Var_Check;
            if (Temp_Var_Check != "SD_Done") {
                Search_Var.push_back(Temp_Var_Check);
            }
            else {
                break;
            }
        }

        while (i <= Search_Var.size() - 1) {
            auto status = filesystem::status(Search_Var[i]);

            if (status.type() == file_type::regular) {
                cout << "File found >> " << Search_Var[i] << " << File found | Count i - " << i << endl;
            }
            else if (status.type() == file_type::directory) {
                cout << "Folder found >> " << Search_Var[i] << " << Folder found | Count i - " << i << endl;
            }
            else {
                cout << "Unknown >> "  << Search_Var[i] << " << Unknown | Count i - " << i << endl;
            }
            i++;
        }
    }
}

// Дерево | ЕЩЁ НЕ ГОТОВО ПОЛНОСТЬЮ!
void FF_Tree() {
    cout << endl;
    vector<path> FilesAndFolders;
    string Temp_Var;

    string inputPath;
    path MainPath;

    if (inputPath.empty()) {
        inputPath = /*current_path();*/ "./";
    }
 
 
    for (auto& p : recursive_directory_iterator(inputPath))
    {
        MainPath = p;
        Temp_Var = MainPath.path::generic_string();
        FilesAndFolders.push_back(Temp_Var);
    }

    int i = 0;

    vector<path> Folders_List;
    vector<path> Files_List;

    while (i <= (FilesAndFolders.size() - 1) && !(FilesAndFolders.empty())) {
        auto status = filesystem::status(FilesAndFolders[i]);
        if (status.type() == file_type::regular) {
            //cout << "File -- >> " << FilesAndFolders[i] << " << -- File" << endl;
            Files_List.push_back(FilesAndFolders[i]);
        }
        else if (status.type() == file_type::directory) {
            //cout << "Folder -- >> " << FilesAndFolders[i] << " << -- Folder" << endl;
            Folders_List.push_back(FilesAndFolders[i]);
        }
        else {
            cout << "Unknown -- >> " << FilesAndFolders[i] << " << -- Unknown" << endl;
        }

        i++;
    }

    i = 0;

    cout << "----------- >>> [ Files ] <<< -----------" << endl;

    while (i <= (Files_List.size() - 1)) {
        cout << Files_List[i] << endl;
        i++;
    }

    i = 0;
    cout << "----------- >>> [ Folders ] <<< -----------" << endl;

    while (i <= (Folders_List.size() - 1)) {
        cout << Folders_List[i] << endl;
        i++;
    }

    cout << "----------------------------------------------------------" << endl;
}



// Настройки
void settings() {
    NameCommand = "Settings";
    int a;
    string b;
    int c;
    int d;

    printMessage(true, {"What do you want to customize? \n\t0 - Exit settings\n\t1 - Profile\n\t2 - Language\n\t3 - Console Color\n\t4 - Debug Mode\n", "Что вы хотите настроить? \n\t0 - Выйти из настроек\n\t1 - Профиль\n\t2 - Язык\n\t3 - Цвет консоли\n\t4 - Режим отладки\n"});
    cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
    
    while(!(cin >> a))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
    } 

    while (true) {
        if (a == 0) {
            break;
        }
        if (a == 1) {
            NameCommand = "Settings/Profile";
            printMessage(true, {"What do you want to customize? \n\t0 - Exit settings (Profile)\n\t1 - Name\n\t2 - Password\n\t3 - Permissions\n", "Что вы хотите настроить? \n\t0 - Выйти из настроек профиля\n\t1 - Имя\n\t2 - Пароль\n\t3 - Разрешения\n"});
            cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
            cin >> c;
            while (true) {
                string new_var;
                if (c == 0) {
                    break;
                }
                else if (c == 1) {
                    printMessage(true, {"Enter a new username", "Введите новое имя пользователя"});
                    cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
                    cin >> ws;
                    cout << "----------------------------------------------------------" << endl;

                    getline(cin, new_var);

                    EditData("UserName", new_var);
                    ReadDataFile();
                    cout << "----------------------------------------------------------" << endl;
                    break;
                }
                else if (c == 2) {
                    printMessage(true, {"Enter a new password", "Введите новый пароль"});
                    cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
                    cin >> ws;
                    cout << "----------------------------------------------------------" << endl;

                    getline(cin, new_var);

                    string TempVar;

                    printMessage(true, {"Confirm a new password", "Подтвердите новый пароль"});
                    cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
                    cin >> ws;
                    getline(cin, TempVar);

                    bool NotWrongPassword = false;

                    while(!NotWrongPassword) {
                        if (TempVar == new_var) {
                            EditData("Password", new_var);
                            ReadDataFile();
                            NotWrongPassword = true;
                            break;
                        }
                        else {
                            printMessage(true, {"Wrong password", "Неправильный пароль"});
                        }
                    }
                    cout << "----------------------------------------------------------" << endl;
                    break;
                }
                else if (c == 3) {
                    cout << "Coming soon..." << endl;
                    break;
                }
            }
            break;
        } 
        else if (a == 2) {
            NameCommand = "Settings/Language";
            cout << "RU - Russian\nEN - English\n";
            cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
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
            break;
        } 
        else if (a == 3) {
            NameCommand = "Settings/Console Color";
            cout << "[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
            printMessage(true, {"Type in (Console Color)", "Введите (Console Color)"});
            cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";

            while(!(cin >> c))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                printMessage(true, {"Type in (Console Color)", "Введите (Console Color)"});
                cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
            } 

            printMessage(true, {"Type in (Text Color)", "Введите (Text Color)"});
            cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";

            while(!(cin >> d))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                printMessage(true, {"Type in (Text Color)", "Введите (Text Color)"});
                cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
            } 

            if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
                string colorCode = "color " + to_string(c) + to_string(d);
                system(colorCode.c_str());
                EditData("ColorsConsole", to_string(c) + to_string(d));
                cout << "----------------------------------------------------------" << endl;
                LogMessage("DONE", {"The color of the line command has been changed. Here's the code: " + to_string(c) + to_string(d), "Цвет командой строки изменён. Вот код: " + to_string(c) + to_string(d)}, 000);
            }
            break;
        } 
        else if (a == 4) {
            NameCommand = "Settings/Debug Mode";
            cout << "True/ON | False/OFF" << endl;
            cout << "[ " + User_Settings["username"] + "/" + NameCommand + " ] >>> ";
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
            break;
        }
    }
}

void Nothing() {
    
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