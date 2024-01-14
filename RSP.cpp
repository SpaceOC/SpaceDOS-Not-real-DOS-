#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "other.h"

using namespace std;

// Камень, ножницы, бумага!
void RSP() {
    int a;
    cout << "Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
    cin >> a;

    LogMessage("DONE", {"", "| [RSP] - Игрок выбрал число: " + to_string(a)}, 000);

    int v = rand() % 3 + 1;

    LogMessage("DONE", {"", "| [RSP] - Система выбрала число: " + to_string(v)}, 000);

    if (a == v) {
        cout << "Tie!" << endl;
        LogMessage("DONE", {"", "| [RSP] - Случилась ничья"}, 000);
    }
    else if (a == 1 && v == 2) {
        cout << "The rock breaks the scissors! The computer lost." << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
    }
    else if (a == 2 && v == 3) {
        cout << "The scissors cut the paper. The computer lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
    }
    else if (a == 2 && v == 1) {
        cout << "The rock breaks the scissors! Player lost." << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
    }
    else if (a == 3 && v == 2) {
        cout << "The scissors cut the paper. The player has lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
    }
    else if (a == 1 && v == 3) {
        cout << "Paper covers stone... The player has lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
    }
    else if (a == 3 && v == 1) {
        cout << "Player wins! Paper covers rock" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
    }
    else {
        cout << "Вы, возможно, написали неверное число или символы. Чтобы игра нормальна работала пишите только \"1\", \"2\" и \"3\"" << endl;
        cout << "----------------------------------------------------------" << endl;
        LogMessage("DONE", {"", "| [RSP] - Игрок выбрал неверное число"}, 000);
    }
}