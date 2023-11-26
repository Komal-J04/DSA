// SOLN 1 - brute force
// doesnt pass 1 test case because that test case needs space optimization

#include <bits/stdc++.h>
class NStack
{
public:
    // Initialize your data structure.
    int s;
    int n;
    vector<int> arr;
    vector<int> top;

    NStack(int N, int S)
    {
        // Write your code here.
        this->s = S; // size of array
        this->n = N; // no of stacks
        for (int i = 0; i < S; i++)
            arr.push_back(-1);
        for (int i = 0; i < N; i++)
        {
            top.push_back(i * (S / N) - 1); // because we are first incrementing top then adding element
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (top[m - 1] >= ((m * s) / n))
            return false;
        top[m - 1]++;
        arr[top[m - 1]] = x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if (top[m - 1] < ((m - 1) * (s / n)))
            return -1;
        int p = arr[top[m - 1]];
        top[m - 1]--;
        return p;
    }
};

// SOLN 2 - space optimized when compared to SOLN 1
// T.C. - O(1)      S.C.-O(s+n)
#include <bits/stdc++.h>
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    int n;
    int s;
    int freespot;

    NStack(int N, int S)
    {
        this->n = N;
        this->s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < N; i++)
            top[i] = -1;

        for (int i = 0; i < S - 1; i++)
            next[i] = i + 1;
        next[S - 1] = -1;

        freespot = 0;
    }

    bool push(int x, int m) // T.C. - O(1)
    {
        // check for overflow
        if (freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) // T.C. - O(1)
    {
        // check for underflow
        if (top[m - 1] == -1)
            return -1;

        // reverse of push will be pop
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};