#include<iostream>
using namespace std;

int main(){
    cout<<"Enter 2 numbers and the operation"<<endl;
    int a,b;
    char op;
    cin>>a>>b>>op;
    switch (op)
    {
    case '+' : cout<<(a+b);
               break;
    case '-' : cout<<(a-b);
               break;
    case '*' : cout<<(a*b);
               break;
    case '/' : cout<<(a/b);
               break;
    case '%' : cout<<(a%b);
               break;
    
    default : cout<<"Please enter a valid operation";
    }
}