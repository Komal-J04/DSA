#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a=0,b=1;
    cout<<"0 1 ";
    for(int i=1;i<=n;i++){
        int newNumber = a + b;
        cout<<newNumber<<" ";
        a=b;
        b=newNumber;
    }
}