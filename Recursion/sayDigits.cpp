#include<iostream>
using namespace std;

void sayDigits(int n)
{
    if(n <= 0) return;

    sayDigits(n/10);

    switch(n%10)
    {
        case 0 : 
                    cout<<"zero ";
                    break;
        case 1 : 
                    cout<<"one ";
                    break;
        case 2 : 
                    cout<<"two ";
                    break;
        case 3 : 
                    cout<<"three ";
                    break;
        case 4 : 
                    cout<<"four ";
                    break;
        case 5 : 
                    cout<<"five ";
                    break;
        case 6 : 
                    cout<<"six ";
                    break;
        case 7 : 
                    cout<<"seven ";
                    break;
        case 8 : 
                    cout<<"eight ";
                    break;
        case 9 : 
                    cout<<"nine ";
                    break;
    }
}

int main()
{
    int n;
    cout<<"Enter number - ";
    cin>>n;

    sayDigits(n);
}