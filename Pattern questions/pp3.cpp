#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int j;
        for(j=1;j<=n;j++){ //for(j=n;j>=1;j--) 4 3 21 ...
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//For n=4
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4