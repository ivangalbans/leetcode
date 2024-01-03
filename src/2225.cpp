// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution
{
public:
    const int MAXN = 1e5 + 1;
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> in_deg(MAXN), out_deg(MAXN);
        for (auto m : matches)
        {
            in_deg[m[1]]++;
            out_deg[m[0]]++;
        }

        vector<vector<int>> ans(2);
        for (int i = 1; i < MAXN; ++i)
        {
            if (!in_deg[i] && out_deg[i])
                ans[0].push_back(i);
            if (in_deg[i] == 1)
                ans[1].push_back(i);
        }

        return ans;
    }
};