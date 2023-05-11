#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> numbers;

    cout<<"Empty or not - "<<numbers.empty()<<endl;
    numbers.push(0);
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    stack<int>copy(numbers);

    cout<<"Top element before popping = "<<numbers.top()<<endl;
    cout<<"Size before popping = "<<numbers.size()<<endl;

    numbers.pop();
    cout<<"Top element after popping = "<<numbers.top()<<endl;
    cout<<"Size after popping = "<<numbers.size()<<endl;

    cout<<"Empty or not - "<<numbers.empty()<<endl;

    cout<<"Contents of the copy stack are => ";
    while(!copy.empty())
    {
        cout<<copy.top()<<" ";
        copy.pop();
    }
}