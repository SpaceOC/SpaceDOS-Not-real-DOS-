#include <iostream>
#include <vector>
#include <random>
#include "Characters_Setup.h"
#include "Characters.h"

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0, 1);


class Sword_Item {
    public:
        double Strength;
        double Durability;
        double Level;
        string Name;
        string Lore;

        void AttackSword1(Enemy_Standart_1& enemy) {
            double HealthEnemy = enemy.Health;
            double probability = dis(gen);
            int i = Level * 0.01;
            if (HealthEnemy <=! 0) {
                if (probability <= 0.15 + i) {
                    cout << "Режущий удар!" << endl;
                    HealthEnemy = enemy.Health - Strength * 0.1 + 1.5;
                    cout << "Вы нанесли противнику " << Strength * 0.1 + 1.5 << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
                else if (probability >= 0.15 - i) {
                    cout << "Обычный удар" << endl;
                    HealthEnemy = enemy.Health - Strength;
                    cout << "Вы нанесли противнику " << Strength << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
            }
            else {
                cout << "Брах его нельзя убить"<< endl;
            }

        }

        void AttackSword2(Enemy_Standart_2& enemy) {
            double HealthEnemy = enemy.Health;
            double probability = dis(gen);
            int i = Level * 0.01;
            if (HealthEnemy <=! 0) {
                if (probability <= 0.15 + i) {
                    cout << "Режущий удар!" << endl;
                    HealthEnemy = enemy.Health - Strength * 0.1 + 1.5;
                    cout << "Вы нанесли противнику " << Strength * 0.1 + 1.5 << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
                else if (probability >= 0.15 - i) {
                    cout << "Обычный удар" << endl;
                    HealthEnemy = enemy.Health - Strength;
                    cout << "Вы нанесли противнику " << Strength << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
            }
            else {
                cout << "Брах его нельзя убить"<< endl;
            }

        }

        void AttackSword3(Enemy_Standart_3& enemy) {
            double HealthEnemy = enemy.Health;
            double probability = dis(gen);
            int i = Level * 0.01;
            if (HealthEnemy <=! 0) {
                if (probability <= 0.15 + i) {
                    cout << "Режущий удар!" << endl;
                    HealthEnemy = enemy.Health - Strength * 0.1 + 1.5;
                    cout << "Вы нанесли противнику " << Strength * 0.1 + 1.5 << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
                else if (probability >= 0.15 - i) {
                    cout << "Обычный удар" << endl;
                    HealthEnemy = enemy.Health - Strength;
                    cout << "Вы нанесли противнику " << Strength << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
            }
            else {
                cout << "Брах его нельзя убить"<< endl;
            }

        }

        void AttackSword4(Enemy_Standart_4& enemy) {
            double HealthEnemy = enemy.Health;
            double probability = dis(gen);
            int i = Level * 0.01;
            if (HealthEnemy <=! 0) {
                if (probability <= 0.15 + i) {
                    cout << "Режущий удар!" << endl;
                    HealthEnemy = enemy.Health - Strength * 0.1 + 1.5;
                    cout << "Вы нанесли противнику " << Strength * 0.1 + 1.5 << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
                else if (probability >= 0.15 - i) {
                    cout << "Обычный удар" << endl;
                    HealthEnemy = enemy.Health - Strength;
                    cout << "Вы нанесли противнику " << Strength << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
            }
            else {
                cout << "Брах его нельзя убить"<< endl;
            }

        }

        void AttackSwordBoss(Enemy_Standart_Boss& enemy) {
            double HealthEnemy = enemy.Health;
            double probability = dis(gen);
            int i = Level * 0.01;
            if (HealthEnemy <=! 0) {
                if (probability <= 0.15 + i) {
                    cout << "Режущий удар!" << endl;
                    HealthEnemy = enemy.Health - Strength * 0.1 + 1.5;
                    cout << "Вы нанесли противнику " << Strength * 0.1 + 1.5 << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
                else if (probability >= 0.15 - i) {
                    cout << "Обычный удар" << endl;
                    HealthEnemy = enemy.Health - Strength;
                    cout << "Вы нанесли противнику " << Strength << " единиц урона! '\n' ХП противника: " << HealthEnemy << endl;
                }
            }
            else {
                cout << "Брах его нельзя убить"<< endl;
            }

        }

        void Reparing() {

        }
    
};

class Gun_Item {

};

class Point_Item {

};

class Block_Item {

};

class Other_Item {

};