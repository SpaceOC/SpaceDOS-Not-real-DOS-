#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "other.h"

using namespace std;

// Counter
void counter() {
    int a; // Минимальное число
    int b; // Максимальное число

    bool Stop = false; // Остановить!

    cout << "----------------------------------------------------------" << endl;
    printMessage(false, {"Min number: ", "Минимальное число: "});

    while(!(cin >> a))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        printMessage(false, {"Min number: ", "Минимальное число: "});
    } 

    a--;

    LogMessage("INFO", {"Minimum number selected by the user: " + to_string(a), "Минимальное число выбранное пользователем: " + to_string(a)}, 000);

    cout << "----------------------------------------------------------" << endl;

    printMessage(false, {"Max number: ", "Максимальное число: "});

    while(!(cin >> b))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        printMessage(false, {"Max number: ", "Максимальное число: "});
    }
    
    LogMessage("INFO", {"| [Counters] The maximum number selected by the user: " + to_string(b), "Максимальное число выбранное пользователем: " + to_string(b)}, 000);

    if (b >= 1000000 || b <= -1000000) {
        string TempVar_HugeNumber;
        Stop = true;
        printMessage(false, {"Max number: ", "Внимание! Данное число является огромным и на окончание работы с таким число потребуется много времени. Вы хотите продолжить?\t"});
        cin >> TempVar_HugeNumber;
        if (TempVar_HugeNumber == "Да" || TempVar_HugeNumber == "Yes" || TempVar_HugeNumber == "да" || TempVar_HugeNumber == "yes") {
            Stop = false;
        }
        else if (TempVar_HugeNumber == "Нет" || TempVar_HugeNumber == "No" || TempVar_HugeNumber == "нет" || TempVar_HugeNumber == "no") {
            Stop = true;
        }
        else {
            Stop = true;
        }
    }

    if (a > b) {
        printMessage(true, {"Max number: ", "Минимальное число не может быть больше максимального!!"});
        Stop = true;
    }

    cout << "----------------------------------------------------------" << endl;

    ofstream file("Texts/counter.txt");
    if (file && !Stop) {
        while (a != b) {
            a++;
            cout << a << endl;
            file << a << '\n';
        }
        file.close();
    } else {
        LogMessage("ERROR", {"Error opening counter.txt file", "Ошибка при открытии counter.txt файла"}, 000);
    }

    if (!Stop) {
        cout << "----------------------------------------------------------" << endl;
        printMessage(true, {"It's done! The file is saved in the Texts folder under the name \"counter.txt\"", "Дело сделано! Файл сохранён в папке Texts под названием \"counter.txt\""});
        LogMessage("DONE", {"The file named \"counter.txt\" was saved in the Texts folder successfully.", "Файл под названием \"counter.txt\" был сохранён в папке Texts успешно"}, 000);
        cout << "----------------------------------------------------------" << endl;
        string text; // Выбор - выйти из counter или нет
        printMessage(false, {"Exit?\t", "Выйти?\t"});
        cin >> text;

        if (text == "Yes" || text == "yes" || text == "да" || text == "Да") {
            LogMessage("INFO", {"The \"counter\" command completed successfully.", "Команда \"counter\" завершила работу успешно"}, 000);
        } else if (text == "No" || text == "no" || text == "Нет" || text == "нет") {
            counter();
        } else {
            printMessage(true, {"I don't understand you.", "Я тебя не понял"});
        }
    }
    else {
        counter();
    }
}