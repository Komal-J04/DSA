#include <iostream>
using namespace std;

class Hero
{
    // properties
    int health;

public:
    char level;
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