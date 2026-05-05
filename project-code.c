// Radhe Radhe
//======================//
//    Rishav ka kaam    //
//=====================//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    setColor(7);
}

//======================//
//    Rishav ka kaam    //
//=====================//

// ============================================================
//  PHASE 2 - BASE CLASS + HERO CLASSES + ENEMY CLASSES
// ============================================================

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

    void printTitle() {
    cout << "  ================================================" << endl;
    cout << "       ***   RPG  BATTLE  GAME   ***             " << endl;
    cout << "          Made by Rishu | C++ Project            " << endl;
    cout << "  ================================================" << endl;
    cout << endl;
}
    void takedamage(int dmg)
    {
        int finalDamage = dmg - defense;

        if (finalDamage < 0)
        {
            finalDamage = 0;// ye final damage minus no. na ho iske liye;//
        }

        hp = hp - finalDamage;

        if (hp <= 0)
        {
            hp = 0;// ye bhi same hp minus no. mai na jye;//
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

    int getAttack()
    {
        return attack;
    }

    string getName()
    {
        return name;
    }

    void displayStatus()
    {
        cout << "Player Name : " << name << endl;
        cout << "Current HP  : " << hp << " / " << maxHp << endl;
    }
};

// Radhe Radhe
//======================//
//    Saumya ka kaam    //
//=====================//

class Hero : public Character
{
    int mana;// ek extra power jo hero emergency me use krta hai for survival
    int level;// defines level
    bool isDefending;

public:
    Hero(string n, int h, int max, int a, int de, int m, int lv) : Character(n, h, max, a, de)
    {
        mana = m;
        level = lv;
        isDefending = false;
    }

    void usePotion() // hero ki hp agar kam ho gyi hai to uska hp recover krne ke liye
    {
        if (hp == maxHp)
        {
            cout << name << " ki HP pehle se full hai!" << endl;
        }
        else if (mana <= 0)
        {
            cout << name << " ke paas potion nahi bachi!" << endl;
        }
        else
        {
            int healAmount = 30;
            mana = mana - 1;
            hp = hp + healAmount;
            if (hp > maxHp)
            {
                hp = maxHp;
            }
            cout << name << " ne potion use ki! +" << healAmount << " HP recover hua." << endl;
            cout << "Potions baaki : " << mana << endl;
        }
    }

    void defend()
    {
        isDefending = true;
        cout << name << " defend kar raha hai! Is turn enemy ka attack kam hoga." << endl;
    }

    void takedamage(int dmg)
    {
        if (isDefending)
        {
            dmg = dmg / 2;
            cout << name << " ne defend kiya! Damage half ho gaya." << endl;
            isDefending = false;
        }

        int finalDamage = dmg - defense;
        if (finalDamage < 0)
        {
            finalDamage = 0;
        }

        hp = hp - finalDamage;
        if (hp <= 0)
        {
            hp = 0;
        }
    }

    void levelUp()
    {
        if (isAlive())
        {
            level = level + 1;
            attack = attack + 5;
            maxHp = maxHp + 20;
            cout << name << " Level Up! Level : " << level << endl;
            cout << "Attack +" << 5 << " | Max HP +" << 20 << endl;
        }
    }

    void displayStatus()
    {
        cout << "---------------------------" << endl;
        cout << "Name    : " << name << endl;
        cout << "HP      : " << hp << " / " << maxHp << endl;
        cout << "Attack  : " << attack << endl;
        cout << "Defense : " << defense << endl;
        cout << "Potions : " << mana << endl;
        cout << "Level   : " << level << endl;
        cout << "---------------------------" << endl;
    }

    int getAttack()
    {
        return attack;
    }
};

class Warrior : public Hero
{
public:
    Warrior(string n) : Hero(n, 150, 150, 30, 10, 3, 1)
    {
    }

    int heavyAttack()
    {
        cout << name << " ne HEAVY ATTACK kiya! Extra damage!" << endl;
        return attack + 20;
    }
};

class Archer : public Hero
{
public:
    Archer(string n) : Hero(n, 100, 100, 20, 8, 5, 1)
    {
    }

    int shootArrow()
    {
        cout << name << " ne ARROW SHOOT kiya! Quick damage!" << endl;
        return attack + 15;
    }
};

// Radhe Radhe
//======================//
//    Rohit ka kaam    //
//=====================//

// enemy  class me kuch specail funtion use hua hai   * isliye apko #include <cstdlib>  #include <ctime> ye dono header file use karna hoga *

class Enemy : public Character
{
protected:
    string type;
    int reward;

public:
    Enemy(string n, int h, int max, int a, int de, string t, int r) : Character(n, h, max, a, de)
    {
        type = t;
        reward = r;
    }

    int aiAttack()
    {
        return attack;
    }

    void dropLoot()
    {
        cout << name << " ne " << reward << " gold drop kiya!" << endl;
    }

    void displayStatus()
    {
        cout << "---------------------------" << endl;
        cout << "Type    : " << type << endl;
        cout << "Name    : " << name << endl;
        cout << "HP      : " << hp << " / " << maxHp << endl;
        cout << "Attack  : " << attack << endl;
        cout << "Defense : " << defense << endl;
        cout << "Reward  : " << reward << " gold" << endl;
        cout << "---------------------------" << endl;
    }
};

class Goblin : public Enemy
{
public:
    Goblin(string n) : Enemy(n, 50, 50, 15, 2, "Goblin", 10)
    {
    }

    int quickStrike()
    {
        int chance = rand() % 100;//ye ek function jo big interger number deta hai  jisko agar 100 se division karege tb 0 se 99  ke beech aayega 
        if (chance < 30) // agar 0 se 30 ke bich rahega tb vo double damage
        {
            cout << name << " ne QUICK STRIKE kiya! Double damage!" << endl;
            return attack * 2;
        }
        return attack; // agar 30 se jada fir normal damage
    }
};

class Dragon : public Enemy
{
public:
    Dragon(string n) : Enemy(n, 200, 200, 40, 15, "Dragon", 50)
    {
    }

    int fireAttack()
    {
        cout << name << " ne FIRE ATTACK kiya! 60 damage!" << endl;
        return 60;// strong   ye hamesa 60  ka damage deta hao 
    }
};

// ============================================================
//  PHASE 3 - Game logic chalo suru karte hai game
// ============================================================

void showMainMenu()
{
    setColor(11);
    cout << "========================================" << endl;
    cout << "        RPG BATTLE GAME" << endl;
    cout << "========================================" << endl;
    resetColor();
    cout << " 1. Start Game" << endl;
    cout << " 2. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Apna choice enter karo : ";
}

//======================//
//    Saumya ka kaam    //
//=====================//

void heroSelectionMenu()
{
    setColor(10);
    cout << "\n========================================" << endl;
    cout << "        HERO SELECT KARO" << endl;
    cout << "========================================" << endl;
    resetColor();
    cout << " 1. Warrior" << endl;
    cout << "    HP: 150  |  Attack: 30  |  Potions: 3" << endl;
    cout << "    Special : Heavy Attack (+20 damage)" << endl;
    cout << endl;
    cout << " 2. Archer" << endl;
    cout << "    HP: 100  |  Attack: 20  |  Potions: 5" << endl;
    cout << "    Special : Shoot Arrow (+15 damage)" << endl;
    cout << "========================================" << endl;
    cout << "1 ya 2 enter karo : ";
}

//======================//
//    Rohit ka kaam    //
//=====================//

void enemySelectionMenu()
{
    setColor(12);
    cout << "\n========================================" << endl;
    cout << "        ENEMY SELECT KARO" << endl;
    cout << "========================================" << endl;
    resetColor();
    cout << " 1. Goblin" << endl;
    cout << "    HP: 50  |  Attack: 15  |  Reward: 10 gold" << endl;
    cout << "    Special : 30% chance of Double Strike" << endl;
    cout << endl;
    cout << " 2. Dragon" << endl;
    cout << "    HP: 200  |  Attack: 40  |  Reward: 50 gold" << endl;
    cout << "    Special : Fire Attack (60 damage)" << endl;
    cout << "========================================" << endl;
    cout << "1 ya 2 enter karo : ";
}

void showBattleStatus(Hero* hero, Enemy* enemy)
{
    setColor(14);
    cout << "\n========================================" << endl;
    cout << "           BATTLE STATUS" << endl;
    cout << "========================================" << endl;
    resetColor();
    hero->displayStatus();
    enemy->displayStatus();
}

//======================//
//    Rishav ka kaam    //
//=====================//

void playerTurn(Hero* hero, Enemy* enemy)
{
    int choice;
    setColor(10);
    cout << "\n--- TERA TURN ---" << endl;
    resetColor();
    cout << " 1. Attack" << endl;
    cout << " 2. Use Potion" << endl;
    cout << " 3. Defend" << endl;
    cout << "Choice enter karo : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << hero->getName() << " ne attack kiya!" << endl;
        enemy->takedamage(hero->getAttack());
        cout << "Enemy ko " << hero->getAttack() << " damage hua!" << endl;
        break;

    case 2:
        hero->usePotion();
        break;

    case 3:
        hero->defend();
        break;

    default:
        cout << "Galat choice! Attack ho gaya by default." << endl;
        enemy->takedamage(hero->getAttack());
        break;
    }
}

void enemyTurn(Hero* hero, Enemy* enemy, int enemyType)
{
    setColor(12);
    cout << "\n--- ENEMY KA TURN ---" << endl;
    resetColor();

    int dmg = 0;

    if (enemyType == 1) // Goblin
    {
        Goblin* g = (Goblin*)enemy;
        dmg = g->quickStrike();
    }
    else // Dragon
    {
        Dragon* d = (Dragon*)enemy;
        int fireChance = rand() % 100;
        if (fireChance < 40)
        {
            dmg = d->fireAttack();
        }
        else
        {
            dmg = d->aiAttack();
            cout << enemy->getName() << " ne normal attack kiya!" << endl;
        }
    }

    hero->takedamage(dmg);
}

void gameLoop(Hero* hero, Enemy* enemy, int enemyType)
{
    setColor(11);
    cout << "\n========================================" << endl;
    cout << "         BATTLE START!" << endl;
    cout << "========================================" << endl;
    resetColor();

    while (hero->isAlive() && enemy->isAlive())
    {
        showBattleStatus(hero, enemy);
        playerTurn(hero, enemy);

        if (!enemy->isAlive())
        {
            break;
        }

        enemyTurn(hero, enemy, enemyType);
    }

    if (!enemy->isAlive())
    {
        setColor(10);
        cout << "\n========================================" << endl;
        cout << "         TU JEET GAYA!" << endl;
        cout << "========================================" << endl;
        resetColor();
        enemy->dropLoot();
        hero->levelUp();
    }
    else
    {
        setColor(12);
        cout << "\n========================================" << endl;
        cout << "         GAME OVER!" << endl;
        cout << "========================================" << endl;
        resetColor();
        cout << hero->getName() << " ki HP khatam ho gayi." << endl;
        cout << "Agli baar zyada dhyan se khelna!" << endl;
    }

    cout << "========================================" << endl;
}

// ============================================================
//   Sab ka kaam - MAIN FUNCTION
// ============================================================

void printTitle() {
    setColor(14);
    cout << "  ================================================" << endl;
    cout << "  =     ***   RPG  BATTLE  GAME   ***            =" << endl;
    cout << "  =       Made by SRRH | C++ Project             =" << endl;
    cout << "  ================================================" << endl;
    resetColor();
    cout << endl;
}

int main()

{
    printTitle();
    srand(time(0));

    showMainMenu();

    int menuChoice;
    cin >> menuChoice;

    if (menuChoice == 2)
    {
        cout << "Game se bahar aa gaye. Khel ne ki himat nahi!" << endl;
        return 0;
    }

    // Hero Selection
    heroSelectionMenu();
    int heroChoice;
    cin >> heroChoice;

    Hero* hero = nullptr;

    if (heroChoice == 1)
    {
        string hname;
        cout << "Warrior ka naam enter karo : ";
        cin >> hname;
        hero = new Warrior(hname);
        cout << "\nWarrior " << hname << " ready hai!" << endl;
    }
    else
    {
        string hname;
        cout << "Archer ka naam enter karo : ";
        cin >> hname;
        hero = new Archer(hname);
        cout << "\nArcher " << hname << " ready hai!" << endl;
    }

    // Enemy Selection
    enemySelectionMenu();
    int enemyChoice;
    cin >> enemyChoice;

    Enemy* enemy = nullptr;

    if (enemyChoice == 1)
    {
        enemy = new Goblin("Green Goblin");
        cout << "\nGreen Goblin  maidan mein aa gaya!" << endl;
    }
    else
    {
        enemy = new Dragon("Ballerion The Black Dread");
        cout << "\nBallerion Opened it's eye's!" << endl;
    }

    // Game Loop
    gameLoop(hero, enemy, enemyChoice);

    // Memory cleanup
    delete hero;
    delete enemy;

    return 0;
}
