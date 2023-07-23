// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

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