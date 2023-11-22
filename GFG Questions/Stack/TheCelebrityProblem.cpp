// SOLN 1 - brute force
// T.C. - O(n^2)
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] != 0)
                {
                    flag = false;
                    break;
                }
            }

            for (int j = 0; j < n; j++)
            {
                if (i != j && (M[j][i] != 1))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans = i;
        }

        return ans;
    }
};

// SOLN 2 - using stack
// T.C. - O(n)
class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        // push all elements first
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (M[a][b] == 1)
                st.push(b);
            else if (M[b][a] == 1)
                st.push(a);
        }

        if (st.empty())
            return -1;

        // check if the leftover element in stack is celebrity
        int x = st.top();
        for (int i = 0; i < n; i++)
        {
            if (M[x][i] != 0)
                return -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (i != x && M[i][x] != 1)
                return -1;
        }

        return x;
    }
}

// SOLN 3 - Two pointer approach
// T.C. - O(n)
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (M[i][j] == 1)
                i++; // if i knows j=> i not a celebrity; move to next person
            else if (M[j][i] == 1)
                j--;
            else if (M[i][j] == 0)
                j--; // if 1st doesn't know last=>last is not celebrity
            else if (M[j][i] == 0)
                i++;
        }

        int x = i;

        // check if ith candidate is a celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != x)
            {
                if (M[x][i] != 0 || M[i][x] != 1)
                    return -1;
            }
        }

        return x;
    }
};

// can also be solved by graph(adjacency list), recursion