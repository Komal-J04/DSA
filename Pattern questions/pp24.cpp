#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int value=1;
    for(int i=1;i<=n;i++){
        int val=1;
        for(int j=1;j<=n;j++){
            if(j>=n-i+1) {
                cout<<val;
                val++;
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

// For n=4
//    1
//   12
//  123
// 1234