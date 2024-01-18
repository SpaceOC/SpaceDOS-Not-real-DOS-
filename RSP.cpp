#include <iostream>
#include <string>
#include <fstream>
#include "other.h"

using namespace std;

// Камень, ножницы, бумага!
void RSP() {
    int a;
    printMessage(true, {"\t\tINFO\n 1 - Rock\n 2 - Scissors\n 3 - Paper", "\t\tИНФОРМАЦИЯ\n 1 - Камень\n 2 - Ножницы\n 3 - Бумага"});
    cout << "----------------------------------------------------------" << endl;
    printMessage(false, {"Enter a number between one and three: ", "Выберите число от одного до трёх: "});
    cin >> a;

    LogMessage("DONE", {"| [RSP] - The player has selected a number: " + to_string(a), "| [RSP] - Игрок выбрал число: " + to_string(a)}, 000);

    int v = rand() % 3 + 1;

    LogMessage("DONE", {"| [RSP] - The system has selected a number: " + to_string(v), "| [RSP] - Система выбрала число: " + to_string(v)}, 000);

    cout << "----------------------------------------------------------" << endl;
    
    if (a == v) {
        printMessage(true, {"Tie!", "Ничья!"});
        LogMessage("INFO", {"| [RSP] - There was a tie", "| [RSP] - Случилась ничья"}, 000);
    }

    else if (a == 1 && v == 2) {
        printMessage(true, {"The rock breaks the scissors! The computer lost", "Камень ломает ножницы! Компьютер проиграл"});
        LogMessage("INFO", {"| [RSP] - Computer lost / Player won", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else if (a == 2 && v == 3) {
        printMessage(true, {"The scissors cut the paper. The computer lost!", "Ножницы разрезали бумагу. Компьютер проиграл!"});
        LogMessage("INFO", {"| [RSP] - Computer lost / Player won", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else if (a == 2 && v == 1) {
        printMessage(true, {"The rock breaks the scissors! Player lost!", "Камень ломает ножницы! Игрок проиграл!"});
        LogMessage("INFO", {"| [RSP] - Computer wins / Player loses", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else if (a == 3 && v == 2) {
        printMessage(true, {"The scissors cut the paper. The player has lost!", "Ножницы разрезают бумагу. Игрок проиграл!"});
        LogMessage("INFO", {"| [RSP] - Computer wins / Player loses", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else if (a == 1 && v == 3) {
        printMessage(true, {"Paper covers stone... The player has lost!", "Бумага покрывает камень... Игрок проиграл!"});
        LogMessage("INFO", {"| [RSP] - Computer wins / Player loses", "| [RSP] - Компьютер выйграл / Игрок проиграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else if (a == 3 && v == 1) {
        printMessage(true, {"Player wins! Paper covers rock", "Игрок побеждает! Бумага покрывает камень"});
        LogMessage("INFO", {"| [RSP] - Computer lost / Player won", "| [RSP] - Компьютер проиграл / Игрок выйграл"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }

    else {
        printMessage(true, {"You may have written the wrong number or characters. For the game to work properly, only write \"1\", \"2\", and \"3\"", "Возможно, вы написали неправильное количество символов. Чтобы игра работала правильно, пишите только \"1\", \"2\" и \"3\""});
        LogMessage("INFO", {"| [RSP] - Player selected an incorrect number", "| [RSP] - Игрок выбрал неверное число"}, 000);
        cout << "----------------------------------------------------------" << endl;
    }
}