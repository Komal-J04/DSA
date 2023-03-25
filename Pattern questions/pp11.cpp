#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int val=65;
        while(j<=n){
            cout<<char(val)<<" "; //char('A' + j -1) 
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// For n=3
// A B C
// A B C
// A B C