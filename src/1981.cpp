// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/

class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int index, int val, int target, vector<vector<int>> &dp)
    {
        if (index == mat.size())
            return abs(target - val);

        if (dp[index][val] != INT_MAX)
            return dp[index][val];

        int ans = INT_MAX;
        for (auto v : mat[index])
            ans = min(ans, minimizeTheDifference(mat, index + 1, val + v, target, dp));

        return dp[index][val] = ans;
    }

    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int m = mat.size();
        vector<vector<int>> dp(m, vector<int>(70 * 70 + 1, INT_MAX));
        return minimizeTheDifference(mat, 0, 0, target, dp);
    }
};