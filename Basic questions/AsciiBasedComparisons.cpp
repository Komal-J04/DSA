#include<iostream>
using namespace std;

int main(){
    char ch;
    cin>>ch;
    int num=(int)ch;
    if(num>=65 && num<=90){
        cout<<"This is uppercase";
    }
    else if (num>=97 && num<=122){
        cout<<"This is lowercase";
    }
    else if (num>=48 && num<=57){
        cout<<"This is a number";
    }
}