#include <iostream>
using namespace std;

class Human
{
public:
    int age;
    int height;
    int weight;

    void eat()
    {
        cout << "eating" << endl;
    }
};

class Male : public Human
{
public:
    void sleep()
    {
        cout << "sleeping" << endl;
    }
};

class Ram : public Male
{
public:
    void walk()
    {
        cout << "walking" << endl;
    }
};

int main()
{
    Ram r;
    r.eat();
    r.sleep();
    r.walk();
}