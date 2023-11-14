#include <iostream>
using namespace std;
#include <stack>

int main()
{
    // creation of stack - |_|
    stack<int> s;

    // push operation
    s.push(1); // 1
    s.push(2); // 2 1
    s.push(3); // 3 2 1

    // pop operation
    s.pop(); // 2 1

    // peek operation
    cout << "Top element" << s.top() << endl;

    // is empty
    cout << "Empty? - " << s.empty() << endl;

    // size
    cout << "Size - " << s.size() << endl;

    return 0;
}