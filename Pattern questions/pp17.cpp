#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=i;
        while(j>=1){
            cout<<(char)('A'+n-j)<<" ";
            j--;
        }
        cout<<endl;
        i++;

        // int j=1;
        // char start='A'+n-i;
        // while(j<=i){
        //     cout<<start;
        //     start++;
        //     j++;
        // }
        // cout<<endl;
        // i++;
    }
}

// For n=4
// D
// C D
// B C D
// A B C D