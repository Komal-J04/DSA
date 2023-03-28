#include<iostream>
using namespace std;

int ap(int n){
    return ((3*n)+7);
}

int Numberof1Bits(int x){
    int c=0;
    while(x!=0){
        if(x&1==1) c++;
        x=x>>1;
    }
    return c;
}

int setbits(int a,int b){
    return (Numberof1Bits(a)+Numberof1Bits(b));
}

int fibonacci(int n){
    int a=0,b=1;
    for(int i=2;i<n;i++){
        int next=a+b;
        a=b;
        b=next;
    }
    return b;
}

int main(){
    //AP
    // int n;
    // cin>>n;
    // cout<<ap(n)<<endl;

    //SETBITS
    // int a,b;
    // cin>>a>>b;
    // cout<<setbits(a,b)<<endl;

    //FIBONACCI
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
}