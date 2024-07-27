// APPROACH 1 - BFS

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q; // node-vertical-level
        map<int, map<int, multiset<int>>> mp;      // vertical-level-node at that (level,vertical)
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front().first;
                int vertical = q.front().second.first;
                int lvl = q.front().second.second;
                q.pop();
                mp[vertical][lvl].insert(curr->val);
                if (curr->left)
                    q.push({curr->left, {vertical - 1, lvl + 1}});
                if (curr->right)
                    q.push({curr->right, {vertical + 1, lvl + 1}});
            }
        }

        for (auto x : mp) // each vertical
        {
            vector<int> temp;
            for (auto y : x.second) // each level
            {
                temp.insert(temp.end(), y.second.begin(), y.second.end()); // insert all the elements from y.second.begin() to y.second.end() at temp.end()
            }
            ans.push_back(temp);
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

// APPROACH 2 - DFS
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
    void dfs(TreeNode *root, int vertical, int lvl, map<int, map<int, multiset<int>>> &mp)
    {
        if (!root)
            return;

        mp[vertical][lvl].insert(root->val);

        dfs(root->left, vertical - 1, lvl + 1, mp);
        dfs(root->right, vertical + 1, lvl + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp; // vertical-level-node at that (level,vertical)

        dfs(root, 0, 0, mp);

        for (auto x : mp)
        {
            vector<int> temp;
            for (auto y : x.second)
            {
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};