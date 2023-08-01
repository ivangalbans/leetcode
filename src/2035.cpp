// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

// Meet in the middle + Binary Search

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); ++mask)
        {
            int nbits = 0, sumL = 0, sumR = 0;
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    nbits++;
                    sumL += nums[i];
                    sumR += nums[i + n];
                }
            }
            left[nbits].push_back(sumL);
            right[nbits].push_back(sumR);
        }

        int sum = accumulate(begin(nums), end(nums), 0);

        for (auto &v : right)
            sort(begin(v), end(v));

        int diff = min(abs(sum - 2 * left[n][0]), abs(sum - 2 * right[n][0]));

        for (int lbits = 0; lbits <= n; lbits++)
        {
            int rbits = n - lbits;
            for (auto sumL : left[lbits])
            {
                int sumR = (sum - 2 * sumL) / 2;
                auto pos_itr = lower_bound(begin(right[rbits]), end(right[rbits]), sumR);

                if (pos_itr != end(right[rbits]))
                    diff = min(diff, abs(sum - 2 * (sumL + (*pos_itr))));

                if (pos_itr != begin(right[rbits]))
                    diff = min(diff, abs(sum - 2 * (sumL + (*(--pos_itr)))));
            }
        }

        return diff;
    }
};