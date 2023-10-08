#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Person
{

    // Complete the class
    string name;
    int age;

public:
    void SetValue(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void GetValue()
    {
        cout << "The name of the person is " << name << " and the age is " << age << ".";
    }
};

int main()
{
    string name;
    int age;
    cin >> name >> age;
    Person p;
    p.SetValue(name, age);
    p.GetValue();

    return 0;
}