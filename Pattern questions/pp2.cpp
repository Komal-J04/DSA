#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1; //if we start from 0 we shld go till i<n
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
//For n=5
// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5