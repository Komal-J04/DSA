#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1; //if we start from 0 we shld go till i<n
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}
//For n=4
// ****
// ****
// ****
// ****