#include <iostream>
using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    void fun()
    {
        cout << "B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{

    C obj;
    // obj.fun();
    obj.A::fun();
    obj.B::fun();

    return 0;
}