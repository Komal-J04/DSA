// SOLN 1 - using another stack

#include <bits/stdc++.h>
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> temp;

    while (!myStack.empty())
    {
        temp.push(myStack.top());
        myStack.pop();
    }

    temp.push(x);

    while (!temp.empty())
    {
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}

// SOLN 2 - recursive approach
// T.C.- O(N)    S.C.-O(N)[Recursive stack space]
#include <bits/stdc++.h>

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);

    return myStack;
}
