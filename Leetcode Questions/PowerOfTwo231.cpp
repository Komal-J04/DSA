#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=1,p=0;
    for(int i=0;i<32;i++){
        if(ans==n) {
            cout<<"true";
            break;
        }
        if(ans<INT_MAX/2){
            ans=ans*2;
            p++;
        }
    }
    if(p>=31) cout<<"no";

    //Approach 2(Better approach) - If number of set bits=1 then the no. is divisible by 2
    
}