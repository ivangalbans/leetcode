// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> buckets(2, INT_MAX);
        for (auto x : nums)
        {
            if (x <= buckets[0])
            {
                buckets[0] = x;
            }
            else if (x <= buckets[1])
            {
                buckets[1] = x;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};