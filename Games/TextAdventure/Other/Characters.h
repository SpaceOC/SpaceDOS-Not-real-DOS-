#include <iostream>
#include "Characters_Setup.h"

using namespace std;

// [Враг] - [Сложность: Лёгкая]
class Enemy_Standart_1 : public Enemy {
    public:
        Enemy_Standart_1() {
            Health = 50;
            XP = 25;
            Armor_Resistance = 5;
            Class_Armor = 1;
            Name = "Тест";
            Description = "Какой-то НН";
        }
};

// [Враг] - [Сложность: Нормальная]
class Enemy_Standart_2 : public Enemy {
    public:
        Enemy_Standart_2() {
            Health = 100;
            XP = 50;
            Armor_Resistance = 25;
            Class_Armor = 1;
            Name = "Тест (2)";
            Description = "Какой-то НН";
        }
};

// [Враг] - [Сложность: Нормальная*2]
class Enemy_Standart_3 : public Enemy {
    public:
        Enemy_Standart_3() {
            Health = 150;
            XP = 80;
            Armor_Resistance = 35;
            Class_Armor = 2;
            Name = "Тест (3)";
            Description = "Какой-то НН";
        }
};

// [Враг] - [Сложность: Сложно]
class Enemy_Standart_4 : public Enemy {
    public:
        Enemy_Standart_4() {
            Health = 300;
            XP = 100;
            Armor_Resistance = 65;
            Class_Armor = 2;
            Name = "Тест (4)";
            Description = "Какой-то НН";
        }
};

// [Враг] - [Сложность: Босс!]
class Enemy_Standart_Boss : public Enemy {
    public:
        Enemy_Standart_Boss() {
            Health = 1500;
            XP = 2500;
            Armor_Resistance = 200;
            Class_Armor = 3;
            Name = "Тест (boss)";
            Description = "Какой-то НН [ опасный НН ]";
        }
};