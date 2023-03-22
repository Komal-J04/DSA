#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int sum=0;
    while(i<=n){
        //Printing all numbers
        //cout<<i<<" ";

        //Sum of first n numbers
        //sum=sum+i;

        //Sum of all even numbers between 1 and n
        if(i%2==0){
            sum=sum+i;
        } 
        i++;
    }
    cout<<"Sum is "<<sum;
}