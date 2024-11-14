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
    core::print("\t\tINFO\n 1 - Rock\n 2 - Scissors\n 3 - Paper\n", core::PrintColors::yellow);
    core::print("----------------------------------------------------------\n");
    core::print("Enter a number between one and three: ", core::PrintColors::green);

    while (!(std::cin >> playerChoice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        core::print("Enter a number between one and three: ", core::PrintColors::green);
    }

    int computerChoice = rand() % 3 + 1;
    core::print("----------------------------------------------------------\n");
    
    if (playerChoice == computerChoice) core::print("Tie!\n");
    else if (playerChoice == 1 && computerChoice == 2) core::print("The rock breaks the scissors! The computer lost\n", core::PrintColors::light_green);
    else if (playerChoice == 2 && computerChoice == 3) core::print( "The scissors cut the paper. The computer lost!\n", core::PrintColors::light_green);
    else if (playerChoice == 2 && computerChoice == 1) core::print("The rock breaks the scissors! Player lost!\n", core::PrintColors::light_red);
    else if (playerChoice == 3 && computerChoice == 2) core::print("The scissors cut the paper. The player has lost!\n", core::PrintColors::light_red);
    else if (playerChoice == 1 && computerChoice == 3) core::print("Paper covers stone... The player has lost!\n", core::PrintColors::light_red);
    else if (playerChoice == 3 && computerChoice == 1) core::print("Player wins! Paper covers rock\n", core::PrintColors::light_green);
    else core::print("You may have written the wrong number or characters. For the game to work properly, only write \"1\", \"2\", and \"3\"\n", core::PrintColors::red);
}