#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

// команда help - показывает все команды
void help() {
    cout << "exit - выйти из SpaceDOS" << endl << 
        "help - displays a list of all commands" << endl << 
        "settings - настройки" << endl << 
        "version - shows the version of this \"game\"" << endl << 
        "delete - removes user from Real Life (DANGER!)" << endl << 
        "hi - Hi!" << endl << 
        "RSP - Rock, Scissors, Paper!" << endl << 
        "time - Work Time" << endl << 
        "counter - ..." << endl << 
        "clear - Очистить командную строку" << endl << 
        "say - say" << endl;
    /*
    * А ЧТО ТАК МОЖНО БЫЛО?
    */
    cout << "----------------------------------------------------------" << endl;
}