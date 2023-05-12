#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> m;
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;
    m["d"] = 4;
    m.insert({"e",5});

    cout<<"Before erase"<<endl;
    for(auto i : m)
    {
        cout<<"Key = "<<i.first<<" "<<"Value = "<<i.second<<endl;
    }

    cout<<"Finding a - "<<m.count("a")<<endl;
    cout<<"Finding 1 - "<<m.count("1")<<endl;

    m.erase("a");
    cout<<"After erase"<<endl;
    for(auto i : m)
    {
        cout<<"Key = "<<i.first<<" "<<"Value = "<<i.second<<endl;
    }

    cout<<"Finding c"<<endl;
    auto it=m.find("c");
    for(auto i = it;i!=m.end();i++)
    {
        cout<<"Key = "<<(*i).first<<" "<<"Value = "<<(*i).second<<endl;
    }
}