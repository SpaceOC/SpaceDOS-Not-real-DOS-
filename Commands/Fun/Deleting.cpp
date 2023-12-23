#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

extern string language;

// Шуточное удаления пользователя из реал лайф
void FUNdelete() {
    printMessage(false, "Write the username of the user you want to delete: ", "Напишите username пользователя, которого вы хотите удалить: ");
    
    string d_user;
    cin >> ws;
    getline(cin, d_user);

    printMessage(false, "The reason you want to delete the user?: ", "Напишите причину удаления пользователя: ");
    
    string text;
    cin >> ws;
    getline(cin, text);

    if (language == "Russian") {
        cout << "Начинаем процесс удаления юзера \"" << d_user << "\"..." << '\n';
    }
    else {
        cout << "Begin the process of deleting the user \"" << d_user << "\"..." << '\n';
    }

    Sleep(2000);

    if (language == "Russian") {
        cout << "Пользователь был успешно удалён по причине: \"" << text << "\"" << '\n';
    }
    else {
        cout << "The user was successfully deleted for a reason: \"" << text << "\"" << '\n';
    }
    cout << "----------------------------------------------------------" << endl;
}