#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


vector<string> Phrases_Hello_Shop = {"Привет! Добро пожаловать в мой магазин!", "Здраствуйте, уважаемый человек! Добро пожаловать в мой магазин!",
                                    "Добро пожаловать в мой магазин!", "Оу. Вы очень вовремя пришли! Добро пожаловать в мой магазин!",
                                    "Приветствую вас в своём магазине!"};

vector<string> Phrases_Not_Available_Shop = {"Ох... К сожалению, вы не сможете купить этот предмет, ибо у вас не хватает денег.", "Жаль, но вы не сможете купить это т.к у вас не хватает денег.", "Жаль, но у вас нету денег."};
vector<string> Phrases_Thank_To_Buy_Shop = {"", "", ""};
vector<string> Phrases_Random_Shop = {"", "", ""};
vector<string> Phrases_History_Shop = {"", "", ""};
vector<string> Phrases_Bye_Shop = {"", "", ""};
vector<string> Phrases_Mad_Dialogue_Shop = {"", "", ""};
vector<string> Phrases_Happy_Dialogue_Shop = {"", "", ""};
vector<string> Phrases_Sleep_Dialogue_Shop = {"", "", ""};

class Reputation {
    public:
        int Rep;
        int S;

        void Reputation_Moment(int Reput) {
            Rep = Rep + Reput;
        }
        
        void Check_Reputation() {
            if (Rep < 0 || Rep > 0) {
                S = Rep * 10;
            }
        }
};

class Shop_Guns : public Reputation {
    public:
        string Name;
};

class Shop_Points : public Reputation {
    public:
        string Name;
};

class Shop_Other : public Reputation {
    public:
        string Name;
};