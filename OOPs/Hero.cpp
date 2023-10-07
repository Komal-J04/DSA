#include <iostream>
using namespace std;

class Hero
{
    // properties
    int health;

public:
    char level;

    // default constructor
    Hero()
    {
        cout << "Default constructor" << endl;
    }

    // parameterized constructor
    Hero(int health)
    {
        cout << "this -> " << this << endl;
        this->health = health;
    }
    Hero(int health, char level)
    {
        this->level = level;
        this->health = health;
    }

    // copy constructor
    Hero(Hero &temp)
    {
        cout << "copy constructor" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print()
    {
        cout << "health " << this->health << " level " << this->level << endl;
    }

    int getHealth()
    {
        return health;
    }

    int getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char l)
    {
        level = l;
    }
};