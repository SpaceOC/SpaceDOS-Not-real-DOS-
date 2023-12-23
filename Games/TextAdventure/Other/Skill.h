#include <iostream>
#include <vector>

using namespace std;

class Skill {
    public:
        string Name;
        vector<string> Ability;
        int Class_Ability;
        double What;
};

class Sword_Class : public Skill {

};

class Mine_Class : public Skill {
    
};

class Air_Class : public Skill {
    
};

class Water_Class : public Skill {
    
};