#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

void FUNHacking() {
    printMessage(false, "Enter: ", "Введите username вашей жертвы: ");
    string bruh_username;

    cin >> ws;

    getline(cin, bruh_username);

    printMessage(false, "Reason?: ", "Причина?: ");
    string reason;
    cin >> ws;

    getline(cin, reason);
}