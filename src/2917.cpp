// https://leetcode.com/problems/find-the-k-or-of-an-array/description/

class Solution
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        vector<int> kor(32);
        for (auto x : nums)
        {
            for (int i = 0; i < 32; ++i)
            {
                if (x & (1 << i))
                    kor[i]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (kor[i] >= k)
                ans += (1 << i);
        }

        return ans;
    }
};