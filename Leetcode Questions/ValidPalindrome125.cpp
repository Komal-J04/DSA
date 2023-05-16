//Solution 1
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    //cout<<"S = "<<s<<endl;

    int length = s.length();
    string p ="";

    for(int i=0;i<length;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&& s[i]<='Z') || (s[i]>=48 && s[i]<=57))
        {
            p += s[i];
        }
    }
    //cout<<"P = "<<p<<endl;
    int len = p.length();
    for(int i=0;i<len;i++)
    {
        if(p[i] != p[len-i-1]) return false;
    }
    return true;
    }
};

//Solution 2 - without using a new string
//When the string contains only special characters this method works since while loop goes on till infinity
class Solution {
public:
    bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    //int length = s.length();
    int start=0;
    int end = s.length() - 1;
    while(start<end)
    {
        while (!((s[start]>='A' && s[start]<='Z') || (s[start]>=0 && s[start]<=9))) start++;
        while (!((s[end]>='A' && s[end]<='Z') || (s[end]>=0 && s[end]<=9))) end--;
        if(s[start]!= s[end]) return false;
        start++;
        end--;
    }
    return true;    
    }
};

//Solution 3 - using toLowerCase function rather than inbuilt function
class Solution {
public:

    char toLowerCase(char c)
    {
        if((c>='a' && c<='z') || (c>=0 && c<=9)) return c;
        else
        {
            return c-'A'+'a';
        }
    }

    bool isPalindrome(string s) {

    int length = s.length();
    string p ="";

    for(int i=0;i<length;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&& s[i]<='Z') || (s[i]>=48 && s[i]<=57))
        {
            p += s[i];
        }
    }
    int len = p.length();
    for(int i=0;i<len;i++)
    {
        p[i] = toLowerCase(p[i]);
    }

    for(int i=0;i<len;i++)
    {
        if(p[i] != p[len-i-1]) return false;
    }
    return true;
    }
};