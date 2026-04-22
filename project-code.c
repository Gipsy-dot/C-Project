// Radhe Radhe

#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
    string name;
    int hp;
    int maxHp;
    int attack;
    int defense;

public:
    Character(string n, int h, int max, int a, int de)
    {
        name = n;
        hp = h;
        maxHp = max;
        attack = a;
        defense = de; // ye defense ka kaam karega..mtlb total damage mai se kuch kaam karke hp ko affect hoga;//
    }
    void takedamage(int dmg)
    {

        int finalDamage;
        finalDamage = dmg - defense;

        if (finalDamage < 0)
        {
            finalDamage = 0; // ye final damage minus no. na ho iske liye;//
        }

        hp = hp - finalDamage;

        if (hp <= 0)
        {
            hp = 0; // ye bhi same hp minus no. mai na jye;//
        }
    }

    bool isAlive()
    {
        if (hp > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayStatus()
    {

        cout << "Player Name: " << name << endl;
        cout << "Current HP: " << hp << endl;
    }
};

// Radhe Radhe

class Hero : public Character
{
    int mana;  // ek extra power jo hero emergency me use krta hai for survival
    int level; // defines level
public:
    Hero(string n, int h, int max, int a, int de, int mana, int level) : Character(n, h, max, a, de)
    {
        this->mana = mana;
        this->level = level;
    }
    void usePotion()
    { // hero ki hp agar kam ho gyi hai to uska hp recover krne ke liye
        if (hp < maxHp && mana >= maxHp - hp)
        {
            mana = mana - (maxHp - hp);
            hp = hp + (maxHp - hp);
        }
    }
    void chooseAction()
    {
        int choice;
        cout << "1.Use Potion\n";
        cout << "2.Attack\n";
        cout << "3.Defense\n";
        cout << "4.Exit\n";
        do
        {
            cin >> choice;
            switch (choice)
            {
            case 1:
                usePotion();
                break;
            case 2:
                attack = attack + 1;
                break;
            case 3:
                defense = defense + 1;
                break;
            case 4:
                cout << "Exit\n";
                break;
            }

        } while (choice != 4);
    }
    void levelUp()
    {
        if (attack > 0 && defense > 0 && isAlive() == true)
            level = level + 1;
    }
};

class Warrior : public Hero
{
public:
    Warrior(string n) : Hero(n, 150, 150, 30, 10, 20, 1)
    {
    }

    void heavyAttack()
    {
        attack = attack + 20;
    }
};

class Archer : public Hero
{
public:
    Archer(string n) : Hero(n, 100, 100, 20, 8, 50, 1)
    {
    }

    void shootarrow()
    {
        attack = attack + 15;
    }
};
