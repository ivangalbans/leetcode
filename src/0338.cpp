// https://leetcode.com/problems/counting-bits/

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);

    for (int i = 0; i <= n; ++i) {
      int bits = 0;
      for (int k = 0; k < 32; ++k)
        bits += ((i >> k) & 1);
      ans[i] = bits;
    }

    return ans;
  }
};
