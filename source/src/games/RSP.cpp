#include <iostream>
#include <string>
#include <vector>
#include "Core/base/data/file_manager.h"
#include "Core/base/data/data_manager.h"
#include "Core/base/users/user_manager.h"
#include "Core/base/print.h"
#include "OS/games/RSP.h"

void RSP() {
    int playerChoice;
    core::print(core::colors::yellow, "\t\tINFO\n 1 - Rock\n 2 - Scissors\n 3 - Paper\n");
    core::print("----------------------------------------------------------\n");
    core::print(core::colors::green, "Enter a number between one and three: ");

    while (!(std::cin >> playerChoice))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        core::print(core::colors::green, "Enter a number between one and three: ");
    }

    int computerChoice = rand() % 3 + 1;
    core::print("----------------------------------------------------------\n");
    
    if (playerChoice == computerChoice) core::print("Tie!\n");
    else if (playerChoice == 1 && computerChoice == 2) core::print(core::colors::light_green, "The rock breaks the scissors! The computer lost\n");
    else if (playerChoice == 2 && computerChoice == 3) core::print(core::colors::light_green, "The scissors cut the paper. The computer lost!\n");
    else if (playerChoice == 2 && computerChoice == 1) core::print(core::colors::light_red, "The rock breaks the scissors! Player lost!\n");
    else if (playerChoice == 3 && computerChoice == 2) core::print(core::colors::light_red, "The scissors cut the paper. The player has lost!\n");
    else if (playerChoice == 1 && computerChoice == 3) core::print(core::colors::light_red, "Paper covers stone... The player has lost!\n");
    else if (playerChoice == 3 && computerChoice == 1) core::print(core::colors::light_green, "Player wins! Paper covers rock\n");
    else core::print(core::colors::red, "You may have written the wrong number or characters. For the game to work properly, only write \"1\", \"2\", and \"3\"\n");
}