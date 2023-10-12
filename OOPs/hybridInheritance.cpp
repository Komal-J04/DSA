#include <iostream>
using namespace std;

class A
{
public:
    void fun1()
    {
        cout << "A" << endl;
    }
};

class D
{
public:
    void fun2()
    {
        cout << "D" << endl;
    }
};

class B : public A
{
public:
    void fun3()
    {
        cout << "B" << endl;
    }
};

class C : public A, public D
{
public:
    void fun4()
    {
        cout << "C" << endl;
    }
};

int main()
{

    B b;
    C c;
    b.fun1();
    b.fun3();
    c.fun1();
    c.fun2();
    c.fun4();

    return 0;
}