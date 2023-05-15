#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper); //converting the entire string to uppercase since S is not case sensitive
    //cout<<"S = "<<s<<endl;

    int length = s.length();
    string p ="";

    //appending only the numbers and alphabets to a new string
    for(int i=0;i<length;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&& s[i]<='Z') || (s[i]>=48 && s[i]<=57))
        {
            p += s[i];
        }
    }
    //cout<<"P = "<<p<<endl;
    int len = p.length();
    bool isPalindrome=true;

    //checking for palindrome on the new string
    for(int i=0;i<len;i++)
    {
        if(p[i] != p[len-i-1]) //RETURN FALSE
        {
            isPalindrome = false; 
            break;
        }
    }
    return isPalindrome; //RETURN TRUE
}