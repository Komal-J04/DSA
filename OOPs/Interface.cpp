#include <iostream>
using namespace std;

class Parent
{
public:
    // Pure virtual function
    virtual void fun() = 0;

    void sleeping()
    {
        cout << "sleeping" << endl;
    }
};

class Child : public Parent
{
public:
    void fun()
    {
        cout << "in child class" << endl;
    }
};

int main()
{
    Child c1;
    c1.fun();
    c1.sleeping();
    return 0;
}