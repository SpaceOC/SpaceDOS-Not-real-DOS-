#include <iostream>
#include <vector>
#include <map>
#include "OS/other/counter.h"
#include "Core/base/print.h"
#include "Core/base/data/file_manager.h"

void counter() {
    int a, b = 0;
    print("Min number: ");

    while (!(std::cin >> a)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        print("Min number: ");
    } 
    a--;
    print("Max number: ");

    while (!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        print("Max number: ");
    }
    if (a > b) {
        print(print::colors::red, "The minimum number cannot be greater than the maximum number!!!\n");
        return;
    }
    if (b >= 1000000 || b <= -1000000) {
        std::string yourChoice;
        print(print::colors::yellow, "Attention! This number is huge and it will take a long time to finish working with such a number. Do you want to continue? (Y/N) \t");
        std::cin >> yourChoice;
        if (yourChoice == "N") {
            return;
        }
    }
    print("----------------------------------------------------------\n");
    fileManager FM;
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
        print(print::colors::red, "Error!\n");
        return;
    }
    print("----------------------------------------------------------\n");
    print(print::colors::green, "It's done! The file is saved in the Texts folder under the name \"counter.txt\"\n");
    std::string yourChoice;
    print("Exit? (Y/N) \t");
    std::cin >> yourChoice;
    if (yourChoice == "N") 
        counter();
}