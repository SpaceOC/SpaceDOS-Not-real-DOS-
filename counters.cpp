#include <iostream>
#include <fstream>

using namespace std;

// Counter
void counter() {
    int a; // Минимальное число
    int b; // Максимальное число

    code:
    cout << "----------------------------------------------------------" << endl;
    cout << "Минимальное число: ";
    cin >> a;
    a -= 1;

    cout << "----------------------------------------------------------" << endl;
    cout << "Максимальное число: ";
    cin >> b;

    cout << "----------------------------------------------------------" << endl;
    ofstream file("counter.txt");
    if (file) {
        while (a!= b) {
            a++;
            cout << a << endl;
            file << a << '\n';
        }
        file.close();
    } else {
        cout << "Error opening the data file." << L'\n';
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "Дело сделано!" << endl;
    cout << "----------------------------------------------------------" << endl;
    string text; // Выбор - выйти из counter или нет
    cout << L"Exit?      ";
    cin >> text;

    if (text == "Yes" || text == "yes" || text == "да" || text == "Да") {
        
    } else if (text == "No" || text == "no" || text == "Нет" || text == "нет") {
        goto code;
    } else {
        cout << "Я тебя не понял" << endl;
    }
}