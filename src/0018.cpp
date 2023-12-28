// https://leetcode.com/problems/4sum/description/

// ksum O(N^(K-1))

class Solution
{
public:
    vector<vector<int>> twoSum(int index, vector<int> &nums, long long target)
    {
        int l = index, r = nums.size() - 1;
        vector<vector<int>> ans;
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                ans.push_back({nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1])
                    ++l;
                while (l < r && nums[r] == nums[r - 1])
                    --r;
                l++;
                r--;
            }
            else if (nums[l] + nums[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }

    vector<vector<int>> ksum(int index, int k, vector<int> &nums, long long target)
    {
        if (k == 2)
            return twoSum(index, nums, target);

        vector<vector<int>> ans;
        for (int i = index; i < nums.size(); ++i)
        {
            auto tmp = ksum(i + 1, k - 1, nums, target - nums[i]);
            int init = ans.size();
            for (int j = 0; j < tmp.size(); ++j)
            {
                ans.push_back({nums[i]});
                for (auto item : tmp[j])
                    ans[init + j].push_back(item);
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }

    vector<vector<int>> ksum(int k, vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return ksum(0, k, nums, target);
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        return ksum(4, nums, target);
    }
};