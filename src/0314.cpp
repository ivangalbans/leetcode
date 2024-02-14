// https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/

// Sorting

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
    void verticalOrder(TreeNode *node, vector<array<int, 4>> &order, int row, int col, int &id)
    {
        if (!node)
            return;

        verticalOrder(node->left, order, row + 1, col - 1, id);
        order.push_back({col, row, id++, node->val});
        verticalOrder(node->right, order, row + 1, col + 1, id);
    }
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        vector<array<int, 4>> order;
        int id = 0;
        verticalOrder(root, order, 0, 0, id);
        sort(begin(order), end(order));

        vector<vector<int>> ans;
        if (!order.size())
            return ans;

        ans.push_back({order[0][3]});
        for (int i = 1; i < order.size(); ++i)
        {
            if (order[i][0] == order[i - 1][0])
                ans.back().push_back(order[i][3]);
            else
                ans.push_back({order[i][3]});
        }

        return ans;
    }
};

// BFS

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
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if (!root)
            return {};

        unordered_map<int, vector<int>> colNums;
        queue<pair<int, TreeNode *>> q;

        int left = INT_MAX, right = INT_MIN;
        q.push({0, root});
        while (!q.empty())
        {
            auto [col, node] = q.front();
            q.pop();
            colNums[col].push_back(node->val);

            left = min(left, col);
            right = max(right, col);

            if (node->left)
                q.push({col - 1, node->left});
            if (node->right)
                q.push({col + 1, node->right});
        }

        vector<vector<int>> ans;
        for (int i = left; i <= right; ++i)
            ans.push_back(colNums[i]);

        return ans;
    }
};