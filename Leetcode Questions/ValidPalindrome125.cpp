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