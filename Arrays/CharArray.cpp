#include<iostream>
using namespace std;

int getLength(char name[])
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    {
        count ++ ;
    }
    return count;
}

void Reverse(char str[])
{
    int length = getLength(str);
    for(int i=0; i<length/2 ;i++)
    {
        swap(str[i],str[length-i-1]);
    }
    cout<<"Reversed string = "<<str<<endl;
}

int main()
{
    char str[10];
    cout<<"Enter the string"<<endl;
    cin>>str;

    cout<<"The string is "<<str<<endl;
    cout<<"Length of the string = "<<getLength(str)<<endl;
    Reverse(str);
}