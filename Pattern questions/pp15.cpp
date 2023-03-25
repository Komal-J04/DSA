#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int val=65;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<(char)val<<" ";
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// For n=4
// A
// B C
// D E F
// G H I J