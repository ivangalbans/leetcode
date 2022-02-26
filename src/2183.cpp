// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

class Solution {
public:
  long long countPairs(vector<int> &nums, int k) {
    unordered_map<int, int> gcd_cnt;
    long long ans = 0;

    for (auto &x : nums) {
      long long gcd1 = gcd(x, k);
      for (auto &[gcd2, cnt] : gcd_cnt)
        if (gcd1 * gcd2 % k == 0)
          ans += cnt;
      ++gcd_cnt[gcd1];
    }

    return ans;
  }
};
