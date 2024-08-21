// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<vector<int>> adjList(N + 1);
        for (auto x : edges)
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }

        queue<int> q;
        q.push(src);
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto x : adjList[node])
            {
                if (dist[x] > (dist[node] + 1))
                {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends