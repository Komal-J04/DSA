#include<iostream>
using namespace std;

int main(){
    int size;
    cin>>size;

    int arr[20];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int x=0;
    for(int i=0;i<size;i++){
        x=x ^ arr[i];
    }
    cout<<x;
}