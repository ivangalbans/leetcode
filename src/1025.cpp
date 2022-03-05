// https://leetcode.com/problems/divisor-game/

class Solution {
public:
  bool divisorGame(int n) {
    vector<bool> dp(n + 1);

    for (int i = 2; i <= n; ++i) {
      for (int d = 1; d * d <= i; ++d)
        if (i % d == 0)
          dp[i] = dp[i] || !dp[i - d];
    }

    return dp[n];
  }
};
