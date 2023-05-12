#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int, vector<int>, greater<int> > mini;

    maxi.push(3);
    maxi.push(12);
    maxi.push(45);
    maxi.push(0);
    maxi.push(100);

    cout<<"Elements of max heap are - ";
    int nmax = maxi.size();
    for(int i=0;i<nmax;i++) //cannot directly put condition that i<maxi.size() because maxi.size() changes with each iteration 
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    } cout<<endl;


    mini.push(3);
    mini.push(12);
    mini.push(45);
    mini.push(0);
    mini.push(100);

    cout<<"Min heap empty? - "<<mini.empty()<<endl;
    cout<<"Elements of min heap are - ";
    int nmin = mini.size();
    for(int i=0;i<nmin;i++) //cannot directly put condition that i<mini.size() because mini.size() changes with each iteration 
    {
        cout<<mini.top()<<" ";
        mini.pop();
    } cout<<endl;
    cout<<"Min heap empty? - "<<mini.empty()<<endl;
}