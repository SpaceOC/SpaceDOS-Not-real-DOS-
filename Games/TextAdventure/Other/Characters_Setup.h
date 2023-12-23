#include <iostream>
#include <vector>

using namespace std;

class Persona {
    public:
        double Health; // Здоровье персонажа
        double XP; // Опыт персонажа
        double Armor_Resistance; // Прочность брони
        int Class_Armor; // Класс брони
        string Name; // Имя персонажа
        string Description; // Описание персонажа

        void takeDamage(double damage) {
            Health -= damage;
            if (Health < 0) {
                Health = 0;
            }
        }

        void gainExperience(double experience) {
            XP += experience;
        }
};

class Character {
    public:
        double Trust; // Показатель доверия
        vector<string> Enemies; // Враги
        string Clan; // Клан
        bool Leader; // Лидер?
};

class Friend : public Character, public Persona {
};

class Neutral : public Character, public Persona {
};

class Enemy : public Character, public Persona {
};