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

    void print()
    {
        cout << "Inside class - " << level << endl;
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