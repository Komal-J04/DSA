//We face problem when the count of a character is >10. If we try to occupy the next place in the array, it will overlap with the next character's count
class Solution {
public:

    void forPrint(vector<char>arr)
    {
        cout<<"Printing the vector :-";
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void printArray(int arr[])
    {
        for(int i=0;i<26;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int compress(vector<char>& chars) {
        vector<char> temp;
        int count[26]={0};
        for(int i=0;i<chars.size();i++)
        {
            if(chars[i]>='a' && chars[i]<='z') count[chars[i]-'a']++;
            if(count[chars[i]-'a'] > 10) count[chars[i]-'a' + 1 ]++; 
        }

        printArray(count);

        int size=0;
        for(int i=0;i<26;i++)
        {
            if (count[i]>0) size++;
        }

        for(int i=0;i<size;i++)
        {
            if(count[i]==1) temp.push_back(i+'a');
            if(count[i]>1)
            {
                temp.push_back(i+'a');
                cout<<count[i] + '0'<<endl; 
                temp.push_back(count[i] + '0');
            }
            else
            {
            }
        forPrint(temp);
        }


        chars.clear();
        for(int i=0;i<temp.size();i++)
        {
            chars.push_back(temp[i]) ;
        }

        return 2*size;

    }
};



