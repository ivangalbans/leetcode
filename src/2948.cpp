// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

// Disjoint Set - group numbers

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> id(n), ans(n);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int i, int j)
             { return nums[i] < nums[j]; });

        vector<int> group_id{id[0]}, group_val{nums[id[0]]};
        for (int i = 1; i < n; ++i)
        {
            if (abs(nums[id[i]] - nums[id[i - 1]]) > limit)
            {
                sort(begin(group_id), end(group_id));
                for (int j = 0; j < group_id.size(); ++j)
                    ans[group_id[j]] = group_val[j];
                group_id.clear();
                group_val.clear();
            }
            group_id.push_back(id[i]);
            group_val.push_back(nums[id[i]]);
        }

        sort(begin(group_id), end(group_id));
        for (int j = 0; j < group_id.size(); ++j)
            ans[group_id[j]] = group_val[j];

        return ans;
    }
};