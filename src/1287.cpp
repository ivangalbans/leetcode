// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> buckets = {n / 4, n / 2, 3 * n / 4};
        for (auto bucket : buckets)
        {
            int num = arr[bucket];
            int i = lower_bound(begin(arr), end(arr), num) - begin(arr);
            int j = upper_bound(begin(arr), end(arr), num) - begin(arr);
            if (j - i > n / 4)
                return num;
        }

        return -1;
    }
};