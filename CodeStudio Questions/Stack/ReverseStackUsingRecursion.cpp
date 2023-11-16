// T.C. - O(n^2)    S.C.-O(N)
void pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    pushAtBottom(myStack, x);

    myStack.push(num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    pushAtBottom(stack, num);
}