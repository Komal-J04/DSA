#include <iostream>
#include "Hero.cpp"
using namespace std;

// static keyword
int Hero::timeToComplete = 5;

int main()
{
    // creation of an object of hero type - static allocation
    Hero a;
    cout << "size of h - " << sizeof(a) << endl; // padding and greedy alignment
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

    // Hero d(70, 'C');
    // Hero e(d); // e.health=d.health & e.level-d.level
    // cout << "d ";
    // d.print();
    // cout << "e ";
    // e.print();

    Hero f(12, 'D');
    char name[5] = "Alex";
    f.setName(name);
    cout << "f ";
    f.print();
    // use default copy constructor
    Hero g(f); // Hero g=f
    cout << "g ";
    g.print();
    f.name[0] = 'E';
    cout << "f ";
    f.print();
    cout << "g ";
    g.print(); // name[0] is changed in g also
    g = f;
    cout << "g ";
    g.print();

    // Destructor
    delete b; // called automatically for static objects

    // static keyword
    cout << "time to complete(without obj)-" << Hero::timeToComplete << endl;
    Hero h;
    cout << "time to complete(with obj)-" << h.timeToComplete << endl; // not recommended
    Hero i;
    i.timeToComplete = 10; // updates the variable for all other objects as well
    cout << "time to complete h(with obj)-" << h.timeToComplete << endl;
    cout << "time to complete i(with obj)-" << i.timeToComplete << endl;

    // static function
    Hero::random();

    return 0;
}