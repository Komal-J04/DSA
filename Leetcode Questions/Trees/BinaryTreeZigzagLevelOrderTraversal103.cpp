// APPROACH 1 - USING QUEUE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool RToL = false;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> lvl;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                lvl.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            if (RToL)
                reverse(lvl.begin(), lvl.end());
            ans.push_back(lvl);
            RToL = !RToL;
        }

        return ans;
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2 - USING STACK

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        stack<TreeNode *> s1;
        s1.push(root);
        stack<TreeNode *> s2;

        while (!s1.empty() || !s2.empty())
        {
            vector<int> lvl;
            while (!s1.empty())
            {
                TreeNode *curr = s1.top();
                s1.pop();
                lvl.push_back(curr->val);
                if (curr->left)
                    s2.push(curr->left);
                if (curr->right)
                    s2.push(curr->right);
            }
            if (!lvl.empty())
                ans.push_back(lvl);
            lvl.clear();
            while (!s2.empty())
            {
                TreeNode *curr = s2.top();
                s2.pop();
                lvl.push_back(curr->val);
                if (curr->right)
                    s1.push(curr->right);
                if (curr->left)
                    s1.push(curr->left);
            }
            if (!lvl.empty())
                ans.push_back(lvl);
        }

        return ans;
    }
};