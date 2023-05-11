#include<iostream>
#include<vector> //library for vectors
using namespace std;

int main()
{
    vector<int>v;
    cout<<"Capacity = "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity = "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity = "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity = "<<v.capacity()<<endl;

    v.push_back(4);
    cout<<"Capacity = "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Capacity = "<<v.capacity()<<endl;
    cout<<"size = "<<v.size()<<endl;

    cout<<"Element at 3rd index = "<<v.at(3)<<endl;

    cout<<"First element = "<<v.front()<<endl<<"Last element = "<<v.back()<<endl;

    cout<<"Before popping - ";
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    v.pop_back();
    cout<<endl<<"After popping - ";
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl<<"Size before clearing = "<<v.size()<<endl;
    v.clear();
    cout<<"Size after clearing = "<<v.size()<<endl;
    cout<<"Capacity after clearing = "<<v.capacity()<<endl;

    vector<int> a(5);
    for(int i = 0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    
    vector<int> p(5,100);
    for(int i = 0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

    vector<int> pCopy(p);
    for(int i = 0;i<pCopy.size();i++)
    {
        cout<<pCopy[i]<<" ";
    }
    cout<<endl;
}