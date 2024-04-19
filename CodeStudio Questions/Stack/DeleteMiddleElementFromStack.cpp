// SOLN 1

#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int N)
{
    if (count >= N / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, N);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

// SOLN 2
#include <bits/stdc++.h>
void deleteMiddle(stack<int> &inputStack, int N)
{
    int mid = N / 2;
    int *arr = new int[mid + 1];
    int i = 0;
    while (i <= mid)
    {
        arr[i] = inputStack.top();
        inputStack.pop();
        i++;
    }

    // push all except the last element which was popped
    for (int i = mid - 1; i >= 0; i--)
    {
        inputStack.push(arr[i]);
    }

    delete[] arr;
}