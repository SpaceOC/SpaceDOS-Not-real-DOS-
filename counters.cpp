#include <iostream>
#include <fstream>
#include <string>
#include "other.h"

using namespace std;

// Counter
void counter() {
    int a; // Минимальное число
    int b; // Максимальное число

    cout << "----------------------------------------------------------" << endl;
    printMessage(false, {"Min number:", "Минимальное число: "});
    cin >> a;
    a -= 1;
    LogMessage("INFO", {"Minimum number selected by the user: " + to_string(a), "Минимальное число выбранное пользователем: " + to_string(a)}, 000);

    cout << "----------------------------------------------------------" << endl;
    printMessage(false, {"Max number:", "Максимальное число: "});
    cin >> b;
    LogMessage("INFO", {"| [Counters] The maximum number selected by the user: " + to_string(b), "Максимальное число выбранное пользователем: " + to_string(b)}, 000);

    cout << "----------------------------------------------------------" << endl;

    ofstream file("Texts/counter.txt");
    if (file) {
        while (a!= b) {
            a++;
            cout << a << endl;
            file << a << '\n';
        }
        file.close();
    } else {
        LogMessage("ERROR", {"Error opening counter.txt file", "Ошибка при открытии counter.txt файла"}, 000);
    }

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