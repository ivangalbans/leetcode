// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
  void dfs(vector<vector<int>> &g, int u, vector<bool> &mk, vector<int> &top) {
    mk[u] = true;

    for (auto v : g[u])
      if (!mk[v])
        dfs(g, v, mk, top);

    top.push_back(u);
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n, vector<int>());
    for (auto &e : edges)
      g[e[0]].push_back(e[1]);

    vector<set<int>> an(n);
    vector<bool> mk(n);
    vector<int> top;

    for (int i = 0; i < n; ++i)
      if (!mk[i])
        dfs(g, i, mk, top);

    for (int i = n - 1; i >= 0; --i) {
      int u = top[i];
      for (auto &v : g[u]) {
        for (auto &x : an[u])
          an[v].insert(x);
        an[v].insert(u);
      }
    }

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i)
      ans[i] = vector<int>(begin(an[i]), end(an[i]));

    return ans;
  }
};
