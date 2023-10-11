#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

    void bark()
    {
        cout << "barking" << endl;
    }
};

class Human
{
public:
    string colour;
    void speak()
    {
        cout << "speaking" << endl;
    }
};

class Multiple : public Animal, public Human
{
};

int main()
{

    Multiple m;
    m.bark();
    m.speak();

    return 0;
}