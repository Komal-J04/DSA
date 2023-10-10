#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int age;

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
};

int main()
{

    Male obj1;
    cout << obj1.age << endl
         << obj1.weight << endl
         << obj1.height << endl
         << obj1.colour << endl;
    obj1.setWeight(100);
    cout << obj1.weight << endl;
    obj1.sleep();
}