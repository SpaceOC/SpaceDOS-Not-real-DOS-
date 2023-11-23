#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

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

string version = "0.5 Alpha";
string DefaultLanguage = "English";
string DefaultUserName = "defaultuser0";
string language;
string username;

void CreateData() {
    ifstream file("data.data");
    if (!file) {
        ofstream data("data.data");
        if (data) {
            data << "Language: " << DefaultLanguage << '\n';
            data << "UserName: " << DefaultUserName << '\n';
            data.close();
        }
        else {
            cout << "Error opening the data file." << '\n';
        }
    }
    else {
        file.close();
    }
}

void ReadData() {
    ifstream data("data.data");
    if (data) {
        string line;
        bool foundLanguage = false;
        bool foundUsername = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find("Language: ") != string::npos) {
                language = line.substr(10);
                cout << language << '\n';
                foundLanguage = true;
            }
            if (!foundUsername && line.find("UserName: ") != string::npos) {
                username = line.substr(10);
                cout << username << '\n';
                foundUsername = true;
            }
            if (foundLanguage && foundUsername) {
                break;
            }
        }
        data.close();
    }
    else {
        cout << "Error opening the data file." << std::endl;
    }
}

void EditData(const string& field, const string& value) {
    ifstream inputFile("data.data");
    ofstream tempFile("temp.data");
    if (inputFile && tempFile) {
        string line;
        bool fieldFound = false;
        while (getline(inputFile, line)) {
            if (line.find(field) != string::npos) {
                tempFile << field << ": " << value << '\n';
                fieldFound = true;
            }
            else {
                tempFile << line << '\n';
            }
        }
        inputFile.close();
        tempFile.close();
        remove("data.data");
        rename("temp.data", "data.data");
        
        if (!fieldFound) {
            cout << "Field not found." << '\n';
        }
    }
    else {
        cout << "Error opening the data file." << '\n';
    }
}

void fakeLoading() {
    char symbols[] = {'|', '/', '-', '\\'};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Loading " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        cout << "Loading kernel " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        cout << "Loading commands " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        cout << "Launching SpaceDOS " << symbols[index];
        cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false; // Set to true if there is an error
    if (errorCondition) {
        cout << "SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << endl;
        cout << "error" << endl; // Replace "error" with the actual error message
    }
    else {
        cout << "SpaceDOS launched successfully!" << endl;
    }
}

int main(){
    CreateData();
    ReadData();
    setlocale(LC_ALL, "");

    fakeLoading();

    Sleep(2000);

    if(language == "Russian"){
        wcout << L"Добро пожаловать в SpaceDOS!" << '\n';
        wcout << L"Версия SpaceDOS - ";
        wcout << L"[ ";
        cout << version;
        wcout << L" ]" << '\n';
    }
    else{
        cout << "Welcome to SpaceDOS!" << '\n';
        cout << "Version SpaceDOS - " << "[ " << version << " ]" << '\n';
    }

    while (true){
        string command_input;
        

        if(language == "Russian"){
            wcout << L"Введите команду: ";
        }
        else{
            cout << "Enter command: ";
        }
        cin >> command_input;

        if(command_input == "delete"){
            string d_user;
            string text;

            cout << "Write the username of the user you want to delete: ";
            cin.ignore(); // Игнорируем символ новой строки оставшийся после предыдущего ввода
            cin >> d_user;
            cout << "The reason you want to delete the user?: ";
            cin >> text;

            cout << "Begin the process of deleting the user \"" << d_user << "\"..." << '\n';

            Sleep(2000);

            cout << "The user was successfully deleted for a reason: \"" << text << "\"" << '\n';
        }

        if(command_input == "exit"){
            break;
        }

        if(command_input == "hi"){
            cout << "Hi!" << '\n';
        }

        if(command_input == "say"){
            string say_text;
            cout << "Enter text to say: ";
            cin.ignore(); // Игнорируем символ новой строки оставшийся после предыдущего ввода
            getline(cin, say_text);
            cout << say_text << '\n';
        }

        if(command_input == "version"){
            cout << "SpaceDOS " << "[ " << version << " ]" << '\n';
        }

        if(command_input == "help"){
            cout << "help - displays a list of all commands" << '\n' << "version - shows the version of this \"game\"" << '\n' << "delete - removes user from Real Life (DANGER!)" << '\n' << "hi - Hi!" << '\n' << "calculator - Calculator" << '\n' <<"RSP - Rock, Scissors, Paper!" << '\n';
        }

        if(command_input != "help" && command_input != "calculator" && command_input != "version" && command_input != "exit" && command_input != "delete" && command_input != "hi" && command_input != "say" && command_input != "RSP" && command_input != "settings"){
            std::cout << "Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
        }

        if(command_input == "calculator"){
            double Fnum;
            double Snum;
            char op;
            double i_num;

            cout << "Enter the first number: ";
            cin.ignore();
            cin >> Fnum;
            cout << "";
            cout << "Enter the second number: ";
            cin >> Snum;
            cout << "";

            cout << "\"-\" or \"+\" or \"*\" or \"/\"?: ";
            cin >> op;
            cout << "";

            switch(op)
            {
                case '+':
                    std::cout << "Готово! Here's the number: " << Fnum + Snum << std::endl;
                    break;
                case '-':
                    std::cout << "Done! Here's the number: " << Fnum - Snum << std::endl;
                    break;
                case '*':
                    std::cout << "Done! Here's the number: " << Fnum * Snum << std::endl;
                    break;
                case '/':
                    std::cout << "Done! Here's the number: " << Fnum / Snum << std::endl;
                    break;
            }
        }

        if(command_input == "RSP"){ // Rock, Scissors, Paper // Да.. Я не знаю как по другому написать. У меня не работает просто, если напишу Rock, Scissors, Paper вместо "RSP"
            srand(time(0));

            int a;
            cout << "Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
            cin >> a;

            int v = rand() % 3 + 1;

            if (a == v) {
                cout << "Tie!" << endl;
            }
            else if (a == 1 && v == 2) {
                cout << "The rock breaks the scissors! The computer lost." << endl;
            }
            else if (a == 2 && v == 3) {
                cout << "The scissors cut the paper. The computer lost!" << endl;
            }
            else if (a == 2 && v == 1) {
                cout << "The rock breaks the scissors! Player lost." << endl;
            }
            else if (a == 3 && v == 2) {
                cout << "The scissors cut the paper. The player has lost!" << endl;
            }
            else if (a == 1 && v == 3) {
                cout << "Paper covers stone... The player has lost!" << endl;
            }
            else if (a == 3 && v == 1) {
                cout << "Player wins! Paper covers rock" << endl;
            }
        }

        if (command_input == "settings") {
            int a;
            string b;
            int c;
            int d;

            cout << "What do you want to customize?\n1 - Profile\n2 - Language\n3 - Console Color\n";
            cin >> a;

            if (a == 1) {
                string new_username;
                cout << "New username: ";
                cin >> new_username;

                EditData("UserName", new_username);
            } 
            else if (a == 2) {
                cout << "RU - Russian\nEN - English\n";
            cin >> b;

                if (b == "RU") {
                    EditData("Language", "Russian");
                } 
                else if (b == "EN") {
                    EditData("Language", "English");
                }
            } 
            else if (a == 3) {
                cout << "[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
                cout << "Type in: ";
                cin >> c;
                cout << "Type in: ";
                cin >> d;

                if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
                    string colorCode = "color " + to_string(c) + to_string(d);
                    system(colorCode.c_str());
                }
            } 
            else if (a == 4) {
                cout << "ТЫ ЧТО СМОТРИШЬ?! " << std::endl;
            }
        }

    }

    return 0;
}
