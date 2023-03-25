#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int value=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>(n-i)) cout<<i;
            else cout<<" ";
        }
        cout<<endl;
    }
}

// For n=4
//    1
//   22
//  333
// 4444