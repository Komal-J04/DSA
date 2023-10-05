#include <iostream>
#include "Hero.cpp"
using namespace std;

int main()
{
    // creation of an object of hero type
    Hero h;

    cout << "size of h - " << sizeof(h) << endl;

    // getter to access private variable
    cout << "Health -- " << h.getHealth() << endl;
    h.level = 'A';

    // setter to set the value of a variable
    h.setHealth(70);

    cout << "Health is " << h.getHealth() << endl;
    cout << "Level is " << h.level << endl;

    return 0;
}