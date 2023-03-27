#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int s=0,p=1;
    while(n!=0){
        int r=n%10;
        n=n/10;
        s=s+r;
        p=p*r;
    }
    cout<<p-s<<endl;
}