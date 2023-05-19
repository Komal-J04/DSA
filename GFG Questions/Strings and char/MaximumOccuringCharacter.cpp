class Solution
{
    public:
    
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26]={0};
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a' && str[i]<='z') arr[str[i]-'a']++ ; //lowercase
            if(str[i]>='A' && str[i]<='Z') arr[str[i]-'A']++; //uppercase
        }
        int maxIndex=0; //storing index in maxi, because we know the characters relative to array indexes only
        for(int i=0;i<26;i++)
        {
            if(arr[i]>arr[maxIndex]) maxIndex=i;
        }
        return maxIndex+'a';
    }

};