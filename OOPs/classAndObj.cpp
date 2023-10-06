#include <iostream>
#include "Hero.cpp"
using namespace std;

int main()
{
    // creation of an object of hero type - static allocation
    Hero a;
    cout << "size of h - " << sizeof(a) << endl;
    // getter to access private variable
    cout << "Health -- " << a.getHealth() << endl;
    a.level = 'A';
    // setter to set the value of a variable
    a.setHealth(70);
    cout << "a health is " << a.getHealth() << endl;
    cout << "a level is " << a.level << endl;

    // dynamic allocaton (in heap)
    Hero *b = new Hero(10);
    // b->setHealth(70);
    b->setLevel('A');
    cout << "Address of b = " << &b << endl;
    cout << "b health is " << b->getHealth() << endl; // or (*b).getHealth()
    cout << "b level is " << b->level << endl;

    Hero *c = new Hero(20, 'B');
    cout << "c health is " << c->getHealth() << endl;
    cout << "c level is " << c->level << endl;

    return 0;
}