#include<iostream>
using namespace std;

void update1(int n)
{
    n++;
}

void update2(int& n)
{
    n++;
}

int& update3(int& n)
{
    int &a = ++n;
    return a;
}

int main()
{
    // int i = 5;
    // int& j = i; //create a reference variable

    // cout<<i<<endl;
    // i++;
    // cout<<i<<endl;
    // j++;
    // cout<<j<<" "<<i<<endl;

    int n = 5;
    cout<<"Before "<<n<<endl;
    
    cout<<"After "<<update3(n)<<endl;


}