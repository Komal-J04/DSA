#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int value=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>(n-i)){
                cout<<value;
                value++;
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

// For n=4
//    1
//   23
//  456
// 78910