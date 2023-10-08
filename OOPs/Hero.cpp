#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero
{
    // properties
    int health;

public:
    char level;
    char *name;
    static int timeToComplete;

    // default constructor
    Hero()
    {
        cout << "Default constructor" << endl;
        name = new char[100];
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
        char *tem = new char[strlen(temp.name) + 1];
        strcpy(tem, temp.name);
        this->name = tem;
        this->health = temp.health;
        this->level = temp.level;
    }

    // static function
    static int random()
    {
        cout << timeToComplete << "--" << endl;
    }

    void print()
    {
        cout << "[Health:" << this->health << " Level:" << this->level << " Name:" << this->name << "]" << endl;
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

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    ~Hero()
    {
        cout << "Destructor" << endl;
    }
};