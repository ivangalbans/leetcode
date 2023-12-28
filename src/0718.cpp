// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

// DP O(n*m) and O(n*m) space

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = nums1[i - 1] == nums2[j - 1] ? 1 + dp[i - 1][j - 1] : 0;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

// DP O(n*m) and O(m) space

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1));

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i % 2][j] = nums1[i - 1] == nums2[j - 1] ? 1 + dp[(i - 1) % 2][j - 1] : 0;
                ans = max(ans, dp[i % 2][j]);
            }
        }

        return ans;
    }
};