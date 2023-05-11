#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque <int> d;
    cout<<d.max_size()<<endl;
    cout<<"Empty or not - "<<d.empty()<<endl;
    d.push_back(2);
    d.push_front(1);
    d.push_back(3);
    d.push_front(0);
    cout<<"Initially deque => ";
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    cout<<"Element at 1st position = "<<d.front()<<endl;
    cout<<"Element at last position = "<<d.back()<<endl;

    d.pop_front();
    cout<<"After pop_front => ";
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    cout<<"Empty or not - "<<d.empty()<<endl;

    cout<<"Before erasing size = "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+2);
    cout<<"After erasing size = "<<d.size()<<endl;

    cout<<"Current element = "<<d.at(0)<<endl;

    cout<<d.max_size()<<endl;
}