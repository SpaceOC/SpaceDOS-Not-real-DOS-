#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

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

using namespace std;

string version = "0.3 Alpha";

void fakeLoading() {
    char symbols[] = {'|', '/', '-', '\\'};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        std::cout << "Loading " << symbols[index];
        std::cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        std::cout << "\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        std::cout << "Loading kernel " << symbols[index];
        std::cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        std::cout << "Loading commands " << symbols[index];
        std::cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        std::cout << "Launching SpaceDOS " << symbols[index];
        std::cout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false; // Set to true if there is an error
    if (errorCondition) {
        std::cout << "SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << std::endl;
        std::cout << "error" << std::endl; // Replace "error" with the actual error message
    }
    else {
        std::cout << "SpaceDOS launched successfully!" << std::endl;
    }
}

int main(){
    fakeLoading();

    Sleep(2000);

    cout << "Welcome to SpaceDOS!" << '\n';
    cout << "Version SpaceDOS - " << "[ " << version << " ]" << '\n';

    while (true){
        string command_input;

        cout << "Enter command: ";
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

        if(command_input != "help" && command_input != "calculator" && command_input != "version" && command_input != "exit" && command_input != "delete" && command_input != "hi" && command_input != "say" && command_input != "RSP"){
            std::cout << "Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
        }

        if(command_input == "calculator"){
            double Fnum;
            double Snum;
            string text;
            double i_num;

            cout << "Minus? Plus? Split? Multiply?: ";
            cin >> text;

            // Простите за возможный г###окодинг. Я же впервые пишу всё на плюсах

            if(text == "Minus"){
                cout << "Enter the first number: ";
                cin.ignore();
                cin >> Fnum;
                cout << "";
                cout << "Enter the second number: ";
                cin >> Snum;
                cout << "";

                i_num = Fnum - Snum;
                cout << "Done! Here's the number: " << i_num << '\n';
            }

            if(text == "Plus"){
                cout << "Enter the first number: ";
                cin.ignore();
                cin >> Fnum;
                cout << "";
                cout << "Enter the second number: ";
                cin >> Snum;
                cout << "";

                i_num = Fnum + Snum;
                cout << "Done! Here's the number: " << i_num << '\n';
            }

            if(text == "Split"){
                cout << "Enter the first number: ";
                cin.ignore();
                cin >> Fnum;
                cout << "";
                cout << "Enter the second number: ";
                cin >> Snum;
                cout << "";

                i_num = Fnum / Snum;
                cout << "Done! Here's the number: " << i_num << '\n';
            }

            if(text == "Multiply"){
                cout << "Enter the first number: ";
                cin.ignore();
                cin >> Fnum;
                cout << "";
                cout << "Enter the second number: ";
                cin >> Snum;
                cout << "";

                i_num = Fnum * Snum;
                cout << "Done! Here's the number: " << i_num << '\n';
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
    }

    return 0;
}




