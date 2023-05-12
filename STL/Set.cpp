#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(3);
    s.insert(12);
    s.insert(100);
    s.insert(3);
    s.insert(45);
    s.insert(0);
    s.insert(3);
    s.insert(100);

    cout<<"Elements of the set are - ";
    for(auto i : s)
    {
        cout<<i<<" ";
    } cout<<endl;

    set<int>::iterator it = s.begin();
    it++ ;
    it++ ;
    s.erase(it);
    cout<<"Deleting 3rd element - ";
    for(auto i : s)
    {
        cout<<i<<" ";
    } cout<<endl;

    s.erase(s.begin());
    cout<<"Deleting 1st element - ";
    for(auto i : s)
    {
        cout<<i<<" ";
    } cout<<endl;

    cout<<"Count of 5 - "<<s.count(5)<<endl;
    cout<<"Count of 3 - "<<s.count(3)<<endl;

    cout<<"Find function - ";
    set<int>::iterator itr = s.find(45);
    for(auto i = itr ; i!=s.end();i++)
    {
        cout<<*i<<" ";
    } cout<<endl;
}