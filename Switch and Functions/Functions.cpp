#include<iostream>
using namespace std;

int power(){
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    return ans;
}

bool isEven(int n){
    //int n;
    if(n%2==0) return true;
    return false;
}

int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*i;
    }
    return ans;
}

int nCr(int n,int r){
    return ((factorial(n))/(factorial(n-r)*factorial(r)));
}

void printCounting(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
}

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}


int main(){
    // int a,b;
    // cin>>a>>b;
    // cout<<power(a,b)<<endl;

    // int c,d;
    // cin>>c>>d;
    // cout<<power(c,d)<<endl;
    //cout<<power()<<endl;

    int n;
    cin>>n;
    //cout<<isEven(n)<<endl;

    // int r;
    // cin>>r;
    //cout<<nCr(n,r)<<endl;

    //printCounting(n);

    cout<<isPrime(n)<<endl;
}