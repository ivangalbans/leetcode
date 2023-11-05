// https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/

class Solution
{
public:
    int minGroups(vector<int> &freq, int size)
    {
        int groups_cnt = 0;
        for (auto num : freq)
        {
            int d = num / (size + 1);
            int r = num % (size + 1);
            if (r == 0)
                groups_cnt += d;
            else if (size - r <= d)
                groups_cnt += d + 1;
            else
                return INT_MAX;
        }

        return groups_cnt;
    }

    int minGroupsForValidAssignment(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_map<int, int> mp;
        for (auto num : nums)
            mp[num]++;

        vector<int> freq;
        for (auto kv : mp)
            freq.push_back(kv.second);

        int m = *min_element(begin(freq), end(freq));

        int ans = INT_MAX;
        for (int i = 1; i <= m; ++i)
            ans = min(ans, minGroups(freq, i));

        return ans;
    }
};