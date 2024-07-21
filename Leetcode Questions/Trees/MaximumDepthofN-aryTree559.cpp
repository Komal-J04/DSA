/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int maxi = 1; // initialising maxi with 1 so that at leaf nodes, 1 is returned
        for (auto x : root->children)
        {
            int child = maxDepth(x) + 1;
            if (child > maxi)
                maxi = child;
        }
        return maxi;
    }
};