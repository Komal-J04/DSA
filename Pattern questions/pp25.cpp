#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int value=1;
    for(int i=1;i<=n;i++){
        //first square 4*4
        int val=1;
        for(int j=1;j<=n;j++){
            if(j>=n-i+1) {
                cout<<val;
                val++;
            }
            else cout<<" ";
        }
        //2nd square 4*4(taking empty space at (4,4)) 
        int j=i-1;
        while(j>=1){
            cout<<j;
            j--;
        }
        cout<<endl;
    }
}

// For n=4
//    1
//   121
//  12321
// 1234321