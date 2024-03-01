// https://leetcode.com/problems/stickers-to-spell-word/description/

class Solution
{
public:
    int solve(unordered_map<string, int> &dp, vector<vector<int>> &freq_stickers, string target)
    {
        if (dp.count(target))
            return dp[target];

        int ans = INT_MAX;
        vector<int> freq_target(26);
        for (auto ch : target)
            freq_target[ch - 'a']++;

        for (int i = 0; i < freq_stickers.size(); ++i)
        {
            if (freq_stickers[i][target[0] - 'a'] == 0)
                continue;

            string s = "";
            for (int j = 0; j < 26; ++j)
                if (freq_target[j] - freq_stickers[i][j] > 0)
                    s += string(freq_target[j] - freq_stickers[i][j], 'a' + j);

            int sol = solve(dp, freq_stickers, s);
            if (sol != INT_MAX)
                ans = min(ans, 1 + sol);
        }

        return dp[target] = ans;
    }

    int minStickers(vector<string> &stickers, string target)
    {
        int n = stickers.size();
        unordered_map<string, int> dp;
        vector<vector<int>> freq_stickers(n, vector<int>(26));

        for (int i = 0; i < n; ++i)
            for (auto ch : stickers[i])
                freq_stickers[i][ch - 'a']++;

        dp[""] = 0;
        int ans = solve(dp, freq_stickers, target);

        return ans == INT_MAX ? -1 : ans;
    }
};