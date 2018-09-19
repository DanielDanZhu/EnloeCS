#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Pokemon {
    private:
        int healthPoints, attackPower, type;
        vector<string> pokemonDefeated;
    public:
        Pokemon();
        int getHealth() {return healthPoints;}
        int getAttack() {return attackPower;}
        int getType() {return type;}
        void setHealth(int h) {healthPoints = h;}
        void setAttack(int a) {attackPower = a;}
        void setType(int t) {type = t;}

        void intro();
        void pokemonSelect();
};

Pokemon::Pokemon() {
    healthPoints =  attackPower = 0;
    type = -1;
}

void Pokemon::intro() {
    cout << "Hello there traveler (Press enter to continue)";
    cin.get();
    cout << "It seems that you have stumbled upon my abode" << endl;
}

int main() {
    Pokemon m;
    m.intro();
}
