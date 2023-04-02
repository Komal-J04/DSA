#include<iostream>
using namespace std;

int main(){
    int number[100];

    //initialising 1st 16 locations with non zero value 90
    fill_n(number,16,90);

    cout<<"Value at n="<<number[20]<<endl;
    //cout<<"Value at n="<<number[2000];


    //initialising an array
    int second[3]={2,3,4};

    //accessing an element
    cout<<"Value at position 2="<<second[1]<<endl;

    cout<<endl<<"Everything is fine"<<endl<<endl;
}