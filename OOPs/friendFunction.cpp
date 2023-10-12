#include <iostream>
using namespace std;

class Rectangle
{

public:
    int len;
    Rectangle()
    {
        len = 10;
    }
    friend int calcLength(Rectangle &); // if we pass by value, the len is updated in a copy of the object
    friend int printLength(Rectangle);
};

int calcLength(Rectangle &b)
{
    b.len += 10;
}

int printLength(Rectangle b)
{
    cout << "Length = " << b.len << endl;
}

int main()
{

    Rectangle r;
    // cout << r.len << endl;
    calcLength(r);
    // cout << r.len << endl;
    printLength(r);

    return 0;
}