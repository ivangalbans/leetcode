// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

class Solution {
public:
  int mostFrequent(vector<int> &nums, int key) {
    int n = nums.size();
    vector<int> targets;

    for (int i = 0; i < n - 1; ++i)
      if (nums[i] == key)
        targets.push_back(nums[i + 1]);

    int ans = 0;
    int best = 0;
    for (auto target : targets) {
      int c = 0;
      for (int i = 0; i < n - 1; ++i)
        if (nums[i] == key && nums[i + 1] == target)
          ++c;

      if (c > ans) {
        ans = c;
        best = target;
      }
    }

    return best;
  }
};
