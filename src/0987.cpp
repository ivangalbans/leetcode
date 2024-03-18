// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
        int left_col = 0, right_col = 0;
        unordered_map<int, multiset<pair<int, int>>> m;

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto [node, cordinates] = q.front();
            q.pop();
            auto [r, c] = cordinates;
            m[c].insert({r, node->val});

            left_col = min(left_col, c);
            right_col = max(right_col, c);

            if (node->left)
                q.push({node->left, {r + 1, c - 1}});
            if (node->right)
                q.push({node->right, {r + 1, c + 1}});
        }

        vector<vector<int>> vertical_traversal;
        for (int i = left_col; i <= right_col; ++i)
        {
            vertical_traversal.push_back(vector<int>());
            for (auto [r, val] : m[i])
                vertical_traversal.back().push_back(val);
        }

        return vertical_traversal;
    }
};