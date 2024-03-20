// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void build_graph(TreeNode *node, vector<vector<int>> &g)
    {
        if (node->left)
        {
            build_graph(node->left, g);
            g[node->val].push_back(node->left->val);
            g[node->left->val].push_back(node->val);
        }
        if (node->right)
        {
            build_graph(node->right, g);
            g[node->val].push_back(node->right->val);
            g[node->right->val].push_back(node->val);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<vector<int>> g(501);
        build_graph(root, g);

        vector<int> ans;
        vector<int> d(501, -1);

        queue<int> q;
        d[target->val] = 0;
        q.push(target->val);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (d[u] <= k)
            {
                if (d[u] == k)
                    ans.push_back(u);
                for (auto v : g[u])
                {
                    if (d[v] == -1)
                    {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return ans;
    }
};