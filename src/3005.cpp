// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> acc(101);
        for (auto x : nums)
            acc[x]++;

        int freq = *max_element(begin(acc), end(acc));
        return count_if(begin(nums), end(nums), [&](int x)
                        { return acc[x] == freq; });
    }
};