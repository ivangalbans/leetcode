// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// O(N^2)

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> l(n), c(n);

        for (int i = 0; i < n; ++i)
        {
            l[i] = c[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    if (l[j] + 1 == l[i])
                    {
                        c[i] += c[j];
                    }
                    if (l[j] + 1 > l[i])
                    {
                        l[i] = l[j] + 1;
                        c[i] = c[j];
                    }
                }
            }
        }

        int m = *max_element(begin(l), end(l));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (l[i] == m)
            {
                ans += c[i];
            }
        }

        return ans;
    }
};

// O(NlongN)

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;

        vector<vector<pair<int, int>>> dp(n);
        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = lower_bound(begin(dp), begin(dp) + best, nums[i], [](auto v1, int val)
                                { return v1.back().first < val; }) -
                    begin(dp);

            int c = 1;
            int pos = l - 1;
            if (pos >= 0)
            {
                int lo = dp[pos].size() - (lower_bound(rbegin(dp[pos]), rend(dp[pos]), nums[i], [](auto v1, int val)
                                                       { return v1.first < val; }) -
                                           rbegin(dp[pos]));

                c = dp[pos].back().second;
                c -= (lo == 0) ? 0 : dp[pos][lo - 1].second;
            }

            dp[l].push_back({nums[i], dp[l].empty() ? c : dp[l].back().second + c});
            if (l == best)
                ++best;
        }

        return dp[best - 1].back().second;
    }
};