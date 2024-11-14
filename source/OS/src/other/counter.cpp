#include <iostream>
#include <map>
#include "OS/other/counter.h"
#include "Core/base/print.h"
#include "Core/base/data/file_manager.h"
#include "Core/base/utils.h"

void counter() {
    int a = 0;
    int b = 0;
    core::print("Min number: ");

    while (!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        core::print("Min number: ");
    } 
    a--;
    core::print("Max number: ");

    while (!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        core::print("Max number: ");
    }
    if (a > b) {
        core::print("The minimum number cannot be greater than the maximum number!!!\n", core::PrintColors::red);
        return;
    }
    if (b >= 1000000 || b <= -1000000) {
        std::string choice;
        core::print("Attention! This number is huge and it will take a long time to finish working with such a number. Do you want to continue? (Y/N) \t", core::PrintColors::yellow);
        std::cin >> choice;
        if (choice == "N") {
            return;
        }
    }
    core::print("----------------------------------------------------------\n");
    core::FileManager FM;
    FM.createFolder("Texts");
    FM.createFile("Texts/counter.txt");
    std::ofstream file("Texts/counter.txt", std::ios::out);

    if (file) {
        while (a != b) {
            a++;
            std::cout << a << '\n';
            file << a << '\n';
        }
        file.close();
    } 
    else {
        core::print("Error!\n", core::PrintColors::red);
        return;
    }
    core::print("----------------------------------------------------------\n");
    core::print("It's done! The file is saved in the Texts folder under the name \"counter.txt\"\n", core::PrintColors::green);
    std::string choice;
    core::print("Exit? (Y/N) \t");
    std::cin >> choice;
    if (choice == "N") 
        counter();
}

void counterWithArgs(const std::vector<std::string>& args) {
    if (args.empty()) {
        counter();
        return;
    }
    else if (!core::Utils::stringIsNumbers(args.at(0)) || !core::Utils::stringIsNumbers(args.at(1))) {
        core::print("Error\n", core::PrintColors::red);
        return;
    }

    int a = stoi(args.at(0)) - 1;
    int b = stoi(args.at(1));

    if (a > b) {
        core::print("The minimum number cannot be greater than the maximum number!!!\n", core::PrintColors::red);
        return;
    }
    if (b >= 1000000 || b <= -1000000 || a >= 1000000 || a <= -1000000) {
        std::string choice;
        core::print("Attention! This number(s) is huge and it will take a long time to finish working with such a number. Do you want to continue? (Y/N) \t", core::PrintColors::yellow);
        std::cin >> choice;
        if (choice == "N")
            return;
    }

    core::FileManager FM;
    FM.createFolder("Texts");
    FM.createFile("Texts/counter.txt");
    std::ofstream file("Texts/counter.txt", std::ios::out);

    if (file) {
        while (a != b) {
            a++;
            std::cout << a << '\n';
            file << a << '\n';
        }
        file.close();
    } 
    else {
        core::print("Error!\n", core::PrintColors::red);
        return;
    }
    core::print("----------------------------------------------------------\n");
    core::print("It's done! The file is saved in the Texts folder under the name \"counter.txt\"\n", core::PrintColors::green);
}