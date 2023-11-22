#include <iostream>
#include <windows.h>
#include <string>

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

string version = "0.1 Alpha";

int main(){
    cout << "Starting..." << '\n';

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
            cout << "help - displays a list of all commands" << '\n' << "version - shows the version of this \"game\"" << '\n' << "delete - removes user from Real Life (DANGER!)" << '\n' << "hi - Hi!" << '\n';
        }

        if(command_input != "help" && command_input != "version" && command_input != "exit" && command_input != "delete" && command_input != "hi" && command_input != "say"){
            std::cout << "Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
        }
    }

    return 0;
}
