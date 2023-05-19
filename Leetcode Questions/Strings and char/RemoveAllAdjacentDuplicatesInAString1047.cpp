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




//SOLUTION 
class Solution {
public:
    void forPrint(vector<char>arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int compress(vector<char>& chars) {
        int i=0; //for traversing the entire vector
        int n=chars.size();
        int ansIndex=0; //to store the count of each element in the ame vector itself
        while(i<n)
        {
            int j=i+1;
            while(j<n && chars[i]==chars[j])
            {
                j++;
            }
            //We come out of the while loop only when the entire array is traversed or a new character is encountered
            int count = j-i;
            chars[ansIndex++] = chars[i];
            if(count>1)
            {
                string cnt = to_string(count);
                for(char ch : cnt)
                {
                    chars[ansIndex++] = ch;
                }
            }
            forPrint(chars);
            i=j; //first j characters are already traversed
        }
        return ansIndex;
    }
};