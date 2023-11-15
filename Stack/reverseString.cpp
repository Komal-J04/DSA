#include <iostream>
using namespace std;

class Stack
{
public:
    char *arr;
    int top;
    int size;

    Stack(int s)
    {
        this->size = s;
        top = -1;
        arr = new char[s];
    }

    void push(char c)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = c;
        }
    }

    char pop()
    {
        if (top > -1)
        {
            char c = arr[top];
            top--;
            return c;
        }
    }
};

// T.C. - O(N)    S.C. - O(N)
int main()
{
    string str;
    cout << "Enter string" << endl;
    cin >> str;
    Stack s(str.length());

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string output;
    for (int i = 0; i < str.length(); i++)
    {
        output += s.pop();
    }

    cout << output << endl;
}