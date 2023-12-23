#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

void say() {
    printMessage(false, "Enter text to say: ", "Введите текст, который должен быть сказан: ");

    string say_text;
    cin >> ws;
    getline(cin, say_text);

    cout << say_text << '\n';
    cout << "----------------------------------------------------------" << endl;
}
