// APPROACH 1

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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> lvl;

            for (int i = 0; i < sz; i++)
            {
                Node *curr = q.front();
                q.pop();
                lvl.push_back(curr->val);

                for (auto x : curr->children)
                    q.push(x);
            }

            ans.push_back(lvl);
        }

        return ans;
    }
};