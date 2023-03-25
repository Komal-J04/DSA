#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    //checking last bit and the nright shifting
    while(n!=0){
        if((n&1)==1) count++;
        n=n>>1; //right shifting
    }
    cout<<count;
}