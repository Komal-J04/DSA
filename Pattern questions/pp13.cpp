#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // int i=65;
    // while(i<n+65){
    //     int j=65;
    //     while(j<n+65){
    //         cout<<(char)(i+j-65)<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    int i=1;
    while(i<=n){
        // int j=1;
        // while(j<=n){
        //     cout<<(char)('A' + i + j - 2) <<" ";
        //     j++;
        // }
        // cout<<endl;
        // i++;

        int j=1;
        char ch='A'+i-1;
        while(j<=n){
            cout<<ch<<" ";
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// For n=3
// A B C
// B C D
// C D E