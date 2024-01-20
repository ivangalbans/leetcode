// https://leetcode.com/problems/minimize-length-of-array-using-operations/description/

class Solution
{
public:
    int minimumArrayLength(vector<int> &nums)
    {

        int m = *min_element(begin(nums), end(nums));
        int cnt_min = count_if(begin(nums), end(nums), [&](int x)
                               { return x == m; });

        if (cnt_min == 1)
            return 1;

        for (auto x : nums)
            if (x % m != 0)
                return 1;

        return ceil(cnt_min / 2.0);
    }
};