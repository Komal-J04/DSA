// https://www.geeksforgeeks.org/problems/burning-tree/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    Node *tgtNode(Node *root, int target)
    {
        if (!root)
            return NULL;
        if (root->data == target)
            return root;

        Node *left = tgtNode(root->left, target);
        if (left && left->data == target)
            return left;

        Node *right = tgtNode(root->right, target);
        if (right && right->data == target)
            return right;

        return NULL;
    }

    void findParent(Node *root, map<Node *, Node *> &parent)
    {
        if (!root || (!root->left && !root->right))
            return;

        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;

        findParent(root->left, parent);
        findParent(root->right, parent);
    }

    void print(queue<Node *> q)
    {
        while (!q.empty())
        {
            cout << q.front()->data << " ";
            q.pop();
        }
        cout << endl;
    }

    void pr(set<Node *> visited)
    {
        for (const Node *node : visited)
            cout << node->data << " ";

        cout << endl;
    }

    int minTime(Node *root, int target)
    {
        // Your code goes here
        if (!root)
            return 0;

        Node *tgtN = tgtNode(root, target);
        map<Node *, Node *> parent;
        findParent(root, parent);

        set<Node *> visited;
        queue<Node *> q;
        q.push(tgtN);
        visited.insert(tgtN);

        int time = 0;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left && (visited.find(curr->left) == visited.end()))
                {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                if (curr->right && (visited.find(curr->right) == visited.end()))
                {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                if (parent[curr] && visited.find(parent[curr]) == visited.end())
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            if (!q.empty())
                time += 1; // increment only if there are more nodes to process
        }

        return time;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends