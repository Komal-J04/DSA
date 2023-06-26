#include<iostream>
#include<string.h>
using namespace std;

string revString(char* str, int len, string final)
{
    if(len==0) return final;

    //cout<<str<<" "<<len<<endl;

    final += str[len-1];

    return revString(str,len-1,final);

}

void revString2(char* str, int start, int end)
{
    if(start>end) return;

    swap(str[start],str[end]);

    revString2(str,++start,--end);
}

void revString3(char* str, int start, int len)
{
    if(start>len-start-1) return;

    swap(str[start],str[len-start-1]);

    revString3(str,++start,len);
}

string checkPalindrome(string str,int len, string final)
{
    if(len==0) return final;

    //cout<<str<<" "<<len<<endl;

    final += str[len-1];

    return checkPalindrome(str,len-1,final);
}

bool checkPalindrome2(string str,int start,int end)
{
    if(start>end) return 1;

    if(str[start]!=str[end])
    {
        return 0;
    }
    else
    {
        return checkPalindrome2(str,++start,--end);
    }
}

int main()
{
    int len;
    cout<<"Enter the length of the string and the string"<<endl;
    cin>>len;
    char *str = new char[len+1];
    for(int i=0;i<len;i++)
    {
        cin>>str[i];
    }
    str[len] = '\0';

    string temp(str);

    string final="";

    cout<<"Method 1 palindrome =>"<<((temp == checkPalindrome(str,len,final))==1?"Given string is palindrome":"Given string is not palindrome")<<endl;

    cout<<"Method 2 palindrome =>"<<((checkPalindrome2(str,0,len-1)==1)?"Given string is palindrome":"Given string is not palindrome")<<endl;

    final="";

    cout<<"Method 1 =>"<<revString(str,len,final)<<endl;

    revString2(str,0,len-1);
    cout<<"Method 2 =>"<<str<<endl;

    revString3(str,0,len);
    cout<<"Method 3 =>"<<str<<endl;


    delete[] str;
}