#include <iostream>
using namespace std;

class A
{
public:
    void sayHello()
    {
        cout << "Hello" << endl;
    }

    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }

    void sayHello(char name)
    {
        cout << "Hello " << name << endl;
    }

    // default arguments
    int add(int num1, int num2, int num3 = 0, int num4 = 0)
    {
        return num1 + num2 + num3 + num4;
    }
};

class B
{
public:
    int a, b;

    int operator+(B &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "output = " << val2 * val1 << endl;
    }

    void operator()()
    {
        cout << "Operator overloading-bracket" << endl;
    }
};

class Parent
{
public:
    void show()
    {
        cout << "parent" << endl;
    }
};

class Child1 : public Parent
{
public:
    void show()
    {
        cout << "child1" << endl;
    }
};

class Child2 : public Parent
{
};

int main()
{
    // COMPILE TIME POLYMORPHISM
    // fn overloading
    A obj1;
    obj1.sayHello();
    obj1.sayHello('$');
    obj1.sayHello("Komal");
    cout << obj1.add(10, 20) << " " << obj1.add(10, 20, 30) << " " << obj1.add(10, 20, 30, 40) << " " << endl;

    // operator overloading
    B obj2, obj3;
    obj2.a = 9;
    obj3.a = 6;

    obj2 + obj3; // the function is called on obj2 (=> this=obj2) and obj3 is the argument passed
    obj2();

    // RUN TIME POLYMORPHISM
    // fn overriding
    Child1 c1;
    Child2 c2;
    c1.show();
    c2.show();

    return 0;
}