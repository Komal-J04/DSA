#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(100);
    v.push_back(45);
    v.push_back(23);
    v.push_back(150);
    v.push_back(10);
    v.push_back(1);
    sort(v.begin(),v.end());

    for(auto i : v)
    {
        cout<<i<<" ";
    }

    cout<<"\nSearching for 10 - "<<binary_search(v.begin(),v.end(),10)<<endl;
    cout<<"Searching for 5 - "<<binary_search(v.begin(),v.end(),5)<<endl; //count can be used in other containers

    cout<<"Lower bound for 23 - "<<lower_bound(v.begin(),v.end(),23) - v.begin()<<endl;
    cout<<"upper bound for 23 - "<<upper_bound(v.begin(),v.end(),23) - v.begin()<<endl;

    int x = 10 , y = 2;
    cout<<"Max element = "<<max(x,y)<<endl;
    cout<<"min element = "<<min(x,y)<<endl;

    swap(x,y);
    cout<<"x = "<<x<<endl<<"y = "<<y<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"Reversed string is "<<abcd<<endl;

    cout<<"Rotated vector - ";
    rotate(v.begin(),v.begin()+2,v.end());
    for(auto i:v)
    {
        cout<<i<<" ";
    } cout<<endl;

    cout<<"Sorting the vector - ";
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<" ";
    } cout<<endl;
}