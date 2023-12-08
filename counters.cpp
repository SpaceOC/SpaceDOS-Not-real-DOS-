#include <iostream>
#include <fstream>

using namespace std;

void counter() {
    int a;
    int b;

    code:
    wcout << L"----------------------------------------------------------" << endl;
    wcout << L"Минимальное число: ";
    cin >> a;
    a -= 1;

    wcout << L"----------------------------------------------------------" << endl;
    wcout << L"Максимальное число: ";
    cin >> b;

    wcout << L"----------------------------------------------------------" << endl;
    wofstream file("counter.txt");
    if (file) {
        while (a!= b) {
            a++;
            wcout << a << endl;
            file << a << L'\n';
        }
        file.close();
    } else {
        wcout << L"Error opening the data file." << L'\n';
    }

    wcout << L"----------------------------------------------------------" << endl;
    wcout << L"Дело сделано!" << endl;
    wcout << L"----------------------------------------------------------" << endl;
    wstring text;
    wcout << L"Exit?      ";
    wcin >> text;

    if (text == L"Yes" || text == L"yes" || text == L"да" || text == L"Да") {
        
    } else if (text == L"No" || text == L"no" || text == L"Нет" || text == L"нет") {
        goto code;
    } else {
        wcout << L"Я тебя не понял" << endl;
    }
}