class Solution {
public:
    string removeDuplicates(string s) {        
        int i=0;
        while(i<s.length()-1 && !s.empty()) //since the length of s changes whenever 2 adjacent characters are found
        {
            if(s[i]==s[i+1])
            {
                s.erase(i, 2);
                i = max(0, i - 1); //takes the counter back after removing adjacent duplicates to find new adjacent duplicates
            }
            else i++;
        }
        return s;     
    }
};