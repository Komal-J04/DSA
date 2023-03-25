#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=i; //j=1
        while(j>=1){ //j<=i
            cout<<j<<" "; //i-j+1 
            j--;
        }
        cout<<endl;
        i++;
    }
}

//For n=4
// 1 
// 2 1 
// 3 2 1 
// 4 3 2 1 