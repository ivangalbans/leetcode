// https://leetcode.com/problems/create-binary-tree-from-descriptions/

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  TreeNode *findNode(unordered_map<int, TreeNode *> &g, int x) {
    if (g.find(x) == end(g)) {
      g[x] = new TreeNode(x);
    }

    return g[x];
  }
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> g;
    unordered_set<int> mk;

    for (auto &edge : descriptions) {
      auto cur = findNode(g, edge[0]);
      mk.insert(edge[1]);
      if (edge[2] == 0) { // derecha
        cur->right = findNode(g, edge[1]);
      } else {
        cur->left = findNode(g, edge[1]);
      }
    }

    for (auto &edge : descriptions)
      if (mk.find(edge[0]) == end(mk))
        return g[edge[0]];

    return 0;
  }
};
