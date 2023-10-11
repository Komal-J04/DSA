#include <iostream>
using namespace std;

class Human
{
    int age;

protected:
    int height;

public:
    int weight;

    int getAge()
    {
        return this->age;
    }

    void setWeight(int weight)
    {
        this->weight = weight;
    }
};

class Male : public Human
{
public:
    string colour;

    void sleep()
    {
        cout << "Male sleeping" << endl;
    }

    int getHeight()
    {
        return this->height;
    }
};

int main()
{

    // Male obj1;
    // cout << obj1.age << endl; // private data member of any class cannot be inherited
    // cout << obj1.weight << endl
    //      << obj1.height << endl
    //      << obj1.colour << endl;
    // obj1.setWeight(100);
    // cout << obj1.weight << endl;
    // obj1.sleep();

    cout << "-----------------" << endl;

    Male m1;
    cout << m1.getHeight() << endl;
}