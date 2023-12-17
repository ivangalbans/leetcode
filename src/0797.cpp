// https://leetcode.com/problems/all-paths-from-source-to-target/

// DFS

class Solution
{
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &g, int u, vector<int> &path, vector<vector<int>> &ans)
    {
        path.push_back(u);

        if (u == g.size() - 1)
        {
            ans.push_back(path);
        }
        else
        {
            for (auto v : g[u])
                dfs(g, v, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &g)
    {
        int n = g.size();

        vector<int> path;
        vector<vector<int>> ans;
        dfs(g, 0, path, ans);

        return ans;
    }
};