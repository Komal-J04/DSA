#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<(char)(i+'A'-1)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// For n=3
// A
// B B
// C C C