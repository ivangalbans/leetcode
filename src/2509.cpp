// https://leetcode.com/problems/cycle-length-queries-in-a-tree/description/

class Solution
{
public:
    int jumps_to_lca(int x, int y)
    {
        if (x == y)
            return 0;
        return 1 + (x > y ? jumps_to_lca(x / 2, y) : jumps_to_lca(x, y / 2));
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i)
            ans[i] = 1 + jumps_to_lca(queries[i][0], queries[i][1]);

        return ans;
    }
};