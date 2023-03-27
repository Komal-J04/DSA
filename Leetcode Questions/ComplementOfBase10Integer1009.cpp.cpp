#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==0) cout<<"1";
    else{
        int m=n;
        int mask=0;
        while(m!=0){
            m=m>>1;
            mask=mask<<1;
            mask = mask | 1;
        }
        cout<<((~n) & mask);
    }
}