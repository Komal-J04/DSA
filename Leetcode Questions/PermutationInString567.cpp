class Solution {
public:

    bool checkEqual(int count1[26],int count2[26])
    {
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=count2[i]) return 0;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        int count1[26]={0}; //making a count array to store occurences of each character of s1
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>='a' && s1[i]<='z') count1[s1[i]-'a']++;
        }

        //traverse s2 string in window of size s1 length and compare
        int i=0;
        int windowSize = s1.length();
        int count2[26]={0};
        while(i<windowSize && i<s2.length()) //for the 1st window of s2. Suppose if length of window>s2 length
        {
            count2[s2[i]-'a']++;
            i++;
        }
        if(checkEqual(count1,count2)) return 1;

        while(i<s2.length()) //for all the other windows since in each window we need to remove 1 previous character
        {
            count2[s2[i]-'a']++; //adding the new element of the window to the count1ay
            count2[s2[i-windowSize]-'a']--; //removing the element that is no more in the window
            i++;

            if(checkEqual(count1,count2)) return 1; //checking for each window if its equal to s1's count of characters (permutation has the same count of individual characters)
        }
        return 0;
    }
};