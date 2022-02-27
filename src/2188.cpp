// https://leetcode.com/problems/minimum-time-to-finish-the-race/

class Solution {
public:
  int minimumFinishTime(vector<vector<int>> &tires, int changeTime,
                        int numLaps) {
    int n = tires.size();

    vector<vector<int>> no_change(n, vector<int>(20, 1e9));
    for (int i = 0; i < n; ++i) {
      no_change[i][1] = tires[i][0];
      for (int j = 2; j < 20; ++j) {
        if ((long long)no_change[i][j - 1] * tires[i][1] >= 1e9)
          break;
        no_change[i][j] = no_change[i][j - 1] * tires[i][1];
      }

      for (int j = 2; j < 20; ++j) {
        if ((long long)no_change[i][j - 1] + no_change[i][j] >= 1e9)
          break;
        no_change[i][j] += no_change[i][j - 1];
      }
    }

    vector<int> dp(numLaps + 1, 1e9);
    for (auto &tire : tires)
      dp[1] = min(dp[1], tire[0]);

    for (int l = 2; l <= numLaps; ++l) {
      if (l < 20)
        for (int i = 0; i < n; ++i)
          dp[l] = min(dp[l], no_change[i][l]);
      for (int i = max(1, l - 18); i < l; ++i)
        dp[l] = min(dp[l], dp[i] + changeTime + dp[l - i]);
    }

    return dp[numLaps];
  }
};
