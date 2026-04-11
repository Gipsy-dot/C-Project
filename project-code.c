// Radhe Radhe

#include <iostream>
#include <string>

using namespace std;

class Character{

    protected:

    string name;
    int hp;
    int maxHp;
    int attack;
    int defense;

    public:

    Character(string n, int h, int max, int a , int de){

        name = n;
        hp = h;
        maxHp=max;
        attack=a;
        defense=de; //ye defense ka kaam karega..mtlb total damage mai se kuch kaam karke hp ko affect hoga;//
    }

    void takedamage(int dmg){

        int finalDamage;
        finalDamage=dmg-defense;

        if(finalDamage<0){
            finalDamage=0; //ye final damage minus no. na ho iske liye;//
        }

        hp=hp-finalDamage;

        if(hp<=0){
            hp=0; //ye bhi same hp minus no. mai na jye;//
        }
    }

    bool isAlive(){
        if (hp > 0){
            return true;
        }
        else{
            return false;
        }
    }

    void displayStatus(){

        cout<<"Player Name: "<<name<<endl;
        cout<<"Current HP: "<<hp<<endl;
    }

};
