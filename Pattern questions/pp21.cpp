#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i) cout<<i; //cout<<j
            else cout<<" ";
        }
        cout<<endl;
    }
}

// For n=4
// 1111
//  222
//   33
//    4

//On printing j
// 1234
//  234
//   34
//    4