// https://leetcode.com/problems/apply-operations-to-an-array/description/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n - 1; ++i) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int l = 0, r = n-1;
        for(int i = 0; i < n; ++i) {
            int index = nums[i] == 0 ? r-- : l++;
            ans[index] = nums[i];
        }

        return ans;
    }
};
