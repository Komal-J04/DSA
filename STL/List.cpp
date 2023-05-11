#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_front(0);
    l.push_back(10);
    cout<<"Initial list => ";
    for(int i : l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of list = "<<l.size()<<endl;

    l.erase(l.begin());
    cout<<"After erasing starting element => ";
    for(int i : l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> initialized(5,10);
    cout<<"Initialized list => ";
    for(int i : initialized)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> copied(initialized);
    cout<<"Copied list => ";
    for(int i : copied)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}