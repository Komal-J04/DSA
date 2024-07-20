// TC - O(3*N) [iterating over each node thrice]        SC - O(3*N)

#include <bits/stdc++.h>
#include <stack>
#include <iostream>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution
{
public:
    vector<vector<int>> allTraversal(Node *node)
    {
        // code here
        if (!node)
            return {};
        vector<int> pre;
        vector<int> in;
        vector<int> post;
        stack<pair<Node *, int>> s;
        s.push(make_pair(node, 1));
        while (!s.empty())
        {
            Node *curr = s.top().first;
            int lvl = s.top().second;
            s.pop();
            if (lvl == 1)
            {
                pre.push_back(curr->data);
                s.push(make_pair(curr, lvl + 1));
                if (curr->left)
                    s.push(make_pair(curr->left, 1));
            }
            else if (lvl == 2)
            {
                in.push_back(curr->data);
                s.push(make_pair(curr, lvl + 1));
                if (curr->right)
                    s.push(make_pair(curr->right, 1));
            }
            else
                post.push_back(curr->data);
        }
        vector<vector<int>> ans;
        ans.push_back(pre);
        ans.push_back(in);
        ans.push_back(post);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    // int t;
    // scanf("%d ", &t);
    // while (t--)
    // {
    string s, ch;
    getline(cin, s);

    Node *root = buildTree(s);

    vector<vector<int>> ans;
    Solution ob;
    ans = ob.allTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // }
    return 0;
}