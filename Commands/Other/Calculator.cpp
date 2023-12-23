#include <iostream>
#include <sstream>
#include <cctype>
#include <windows.h>
#include <cmath>

using namespace std;

void StandartCalculator(string Calc) {
    stringstream ss(Calc);
    char op = '\0';
    int num1, num2;
    ss >> num1;

    while (ss >> op >> num2) {
        if (op == '+') {
            num1 += num2;
        } else if (op == '-') {
            num1 -= num2;
        } else if (op == '*') {
            num1 *= num2;
        } else if (op == '/') {
            if (num2!= 0) {
                num1 /= num2;
            } else {
                cout << "Деление на ноль невозможно" << endl;
                return;
            }
        } else {
            cout << "Неверный оператор: " << op << endl;
            return;
        }
    }

    std::cout << "Результат: " << num1 << endl;
}

void solveQ(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } 
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "x = " << x << endl;
        }  
        else {
            cout << "Это невозможно..." << endl;
        }
}

void CalculatorSetup(int a) {
    string Whaat;
    cout << "Введите: ";
    switch (a)
    {
    case 1:
        getline(cin >> ws, Whaat);
        StandartCalculator(Whaat);
        break;
    case 2:
        double b;
        double c;
        double x;
        cout << endl << "Введите b: ";
        cin >> b;
        cout << "Введите a: ";
        cin >> c;
        cout << "Введите c: ";
        cin >> x;
        solveQ(b, c, x);
        break;
    default:
        cout << endl << "Неизвестно!";
        break;
    }
}

void Lmao_Moment() {
    int a;
    cout << "1 - Обычный калькулятор" << endl <<
    "2 - Квадратное уравнение" << endl <<
    "3 - Я не придумал. Идите лесом" << endl <<
    "Введите: ";
    cin >> a;
    switch (a)
    {
    case 1:
        CalculatorSetup(1);
        break;
    case 2:
        CalculatorSetup(2);
        break;
    default:
        break;
    }
}