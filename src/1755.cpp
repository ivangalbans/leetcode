// https://leetcode.com/problems/closest-subsequence-sum/description/

class Solution
{
public:
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        vector<int> left, right;
        int llen = n / 2;
        int rlen = n - llen;

        for (int i = 0; i < (1 << llen); ++i)
        {
            int sum = 0;
            for (int j = 0; j < llen; ++j)
            {
                if (i & (1 << j))
                {
                    sum += nums[j];
                }
            }
            left.push_back(sum);
        }

        for (int i = 0; i < (1 << rlen); ++i)
        {
            int sum = 0;
            for (int j = 0; j < rlen; ++j)
            {
                if (i & (1 << j))
                {
                    sum += nums[llen + j];
                }
            }
            right.push_back(sum);
        }

        sort(begin(right), end(right));

        int ans = INT_MAX;
        for (auto v : left)
        {
            auto itr = lower_bound(begin(right), end(right), goal - v);
            if (itr != end(right))
                ans = min(ans, abs(goal - (v + (*itr))));
            if (itr != begin(right))
                ans = min(ans, abs(goal - (v + (*(--itr)))));
        }

        return ans;
    }
};