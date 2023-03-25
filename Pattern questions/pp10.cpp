#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int val=65;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<(char)val<<" ";
            //cout<< (char)('A' + i -1) << " ";
            j++;
        }
        cout<<endl;
        i++;
        val++;
    }
}

// For n=3
// A A A
// B B B
// C C C