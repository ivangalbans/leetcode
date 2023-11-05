// https://leetcode.com/problems/last-stone-weight-ii/description/

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int sum = accumulate(begin(stones), end(stones), 0);
        int w = sum / 2;

        bool dp[3001] = {false};
        dp[0] = true;
        for (int i = 0; i < n; ++i)
            for (int j = w; j >= stones[i]; --j)
                dp[j] |= dp[j - stones[i]];

        for (int j = w; j >= 0; --j)
            if (dp[j])
                return sum - 2 * j;

        return -1;
    }
};