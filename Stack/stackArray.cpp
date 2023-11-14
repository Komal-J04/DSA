#include <iostream>
using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }

    void push(int elt)
    {
        if (top + 1 >= size) // since we are incrementing size after this
        {
            cout << "Stack is full" << endl;
            return;
        }

        top++;
        arr[top] = elt;
    }

    int pop()
    {
        if (top >= 0)
        {
            int elt = arr[top];
            top--;
            return elt;
        }
        cout << "Empty stack" << endl;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        cout << "Empty stack" << endl;
        return -1;
    }
};

int main()
{

    Stack s(5);

    s.push(22);
    s.push(43);
    s.push(44);
    s.push(22);
    s.push(43);
    s.push(44);
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}