#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int s=0;
    int i=2;
    // while(i<n){
    //     if(n%i==0) s++;
    //     i++;
    // }
    // if(s==0) cout<<"Prime";
    // else cout<<"Not prime";

    bool isPrime=1;
    while(i<n){
        if(n%i==0){
            cout<<"Not prime";
            isPrime=0;
            break;
        }
        i++;
    }
    if(isPrime==1) cout<<"Prime";
}