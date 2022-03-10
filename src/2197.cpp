// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    vector<int> v;
    int n = nums.size();
    v.reserve(n);

    for (int i = 0; i < n; ++i) {
      long long lcm = nums[i];
      while (v.size() && gcd(lcm, v.back()) != 1) {
        lcm = ((long long)lcm * v.back()) / gcd(lcm, v.back());
        v.pop_back();
      }
      v.push_back(lcm);
    }

    return v;
  }
};
