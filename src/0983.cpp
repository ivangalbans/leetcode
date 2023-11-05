// https://leetcode.com/problems/minimum-cost-for-tickets/description

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(400, 1e6);
        vector<int> shifts = {1, 7, 30};

        for (int j = 0; j < 3; ++j)
            for (int d = days[0]; d < days[0] + shifts[j]; ++d)
                dp[d] = min(dp[d], costs[j]);

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < 3; ++j)
                for (int d = days[i]; d < days[i] + shifts[j]; ++d)
                    dp[d] = min(dp[d], dp[days[i - 1]] + costs[j]);

        return dp[days[n - 1]];
    }
};