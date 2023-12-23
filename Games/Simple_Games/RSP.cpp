#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "data.h"
#include "other.h"

using namespace std;

// Камень, ножницы, бумага!
void RSP() {
    int a;
    cout << "Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
    cin >> a;

    int v = rand() % 3 + 1;

    if (a == v) {
        cout << "Tie!" << endl;
    }
    else if (a == 1 && v == 2) {
        cout << "The rock breaks the scissors! The computer lost." << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 3) {
        cout << "The scissors cut the paper. The computer lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 1) {
        cout << "The rock breaks the scissors! Player lost." << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 2) {
        cout << "The scissors cut the paper. The player has lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else if (a == 1 && v == 3) {
        cout << "Paper covers stone... The player has lost!" << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 1) {
        cout << "Player wins! Paper covers rock" << endl;
        cout << "----------------------------------------------------------" << endl;
    }
    else {
        cout << "Вы, возможно, написали неверное число или символы. Чтобы игра нормальна работала пишите только \"1\", \"2\" и \"3\"" << endl;
        cout << "----------------------------------------------------------" << endl;
    }
}