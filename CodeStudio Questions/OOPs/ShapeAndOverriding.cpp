#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Shape
{
public:
    string shapeType;
    void printMyType()
    {
    }
};

class Square : public Shape
{
public:
    int length, breadth;

    int calculateArea()
    {
        return this->length * this->breadth;
    }

    void printMyType()
    {
        cout << "square" << endl;
    }
};

class Rectangle : public Shape
{
public:
    int length, breadth;

    int calculateArea()
    {
        return this->length * this->breadth;
    }

    void printMyType()
    {
        cout << "rectangle" << endl;
    }
};

int main()
{

    Square sq;
    sq.length = 5;
    sq.breadth = 5;
    sq.printMyType();
    cout << sq.calculateArea() << endl;
    Rectangle r;
    r.length = 5;
    r.breadth = 4;
    r.printMyType();
    cout << r.calculateArea() << endl;

    return 0;
}