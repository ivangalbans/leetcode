// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

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
    bool find_path(TreeNode *root, int u, string &path)
    {
        if (root->val == u)
            return true;

        if (root->left && find_path(root->left, u, path))
            path.push_back('L');
        else if (root->right && find_path(root->right, u, path))
            path.push_back('R');

        return !path.empty();
    }

    string getDirections(TreeNode *root, int src, int dst)
    {
        string to_src, to_dst;
        find_path(root, src, to_src);
        find_path(root, dst, to_dst);

        int prefix_len = 0;
        int i = 0;
        while (!to_src.empty() && !to_dst.empty() && to_src.back() == to_dst.back())
        {
            to_src.pop_back();
            to_dst.pop_back();
        }

        return string(to_src.length(), 'U') + string(rbegin(to_dst), rend(to_dst));
    }
};