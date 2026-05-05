
// Radhe Radhe 


 
// enemy  class me kuch specail funtion use hua hai   * isliye apko #include <cstdlib>  #include <ctime> ye dono header file use karna hoga *

class Enemy : public Character {
protected:
    string type;
    int reward;

public:
    Enemy(string n, int h, int max, int a, int de, string t, int r): Character(n, h, max, a, de) {
        type = t;
        reward = r;
    }

    int aiAttack() {
        return attack;
    }

    void dropLoot() {
        cout << name << " ne " << reward << " gold drop kiya!" << endl; // enemy agar khatam hoga tb vo gold coin bhi dega 
    }

    void displayStatus() {
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << "/" << maxHp << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Reward: " << reward << " gold" << endl;
    }
};

class Goblin : public Enemy {
public:
    Goblin(string n) : Enemy(n, 50, 50, 15, 2, "Goblin", 10) {}

    int quickStrike() {
        int chance = rand() % 100;  //ye ek function jo big interger number deta hai  jisko agar 100 se division karege tb 0 se 99  ke beech aayega 
        if (chance < 30) {  // agar 0 se 30 ke bich rahega tb vo double damage
            cout << name << " ne QUICK STRIKE kiya  Double damage!" << endl;
            return attack * 2;
        }
        return attack; // agar 30 se jada fir normal damage
    }
};

class Dragon : public Enemy {
public:
    Dragon(string n) : Enemy(n, 200, 200, 40, 15, "Dragon", 50) {}

    int fireAttack() { // strong   ye hamesa 60  ka damage deta hao 
        cout << name << " ne FIRE ATTACK kiya! 60 damage!" << endl;
        return 60;
    }
};




////////////////////////



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
