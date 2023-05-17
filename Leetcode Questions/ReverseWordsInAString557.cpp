//Has an error
class Solution {
public:
    string reverseWords(string s) {
        string p="";
        string k="";
        int len = s.length();
        for(int i=0;i<=len;i++)
        {
            if(s[i]!=' ') p.push_back(s[i]);  // Last word is not detected because '\0\ != ' '
            else
            {
                //cout<<"A Word - "<<p<<endl;
                int start = 0;
                int end = p.length() - 1;
                while(start<end) 
                {
                    swap(p[start],p[end]);
                    start++;
                    end--;
                }
                p.push_back(' ');
                //cout<<"Word after reversing - "<<p<<endl;
                k.append(p);
                //cout<<"String - "<<k<<endl;
                p="";
            }
        }
        k.pop_back();
        return k;
    }
};


//SOLUTION
class Solution {
public:
    string reverseWords(string s) {
        string p="";
        string k="";
        int len = s.length();
        for(int i=0;i<=len;i++)
        {
            if(s[i]==' ' || s[i]=='\0')
            {
                //cout<<"A Word - "<<p<<endl;
                int start = 0;
                int end = p.length() - 1;
                while(start<end) 
                {
                    swap(p[start],p[end]);
                    start++;
                    end--;
                }
                p.push_back(' ');
                //cout<<"Word after reversing - "<<p<<endl;
                k.append(p);
                //cout<<"String - "<<k<<endl;
                p="";
            }
            else p.push_back(s[i]);
        }
        k.pop_back();
        return k;
    }
};