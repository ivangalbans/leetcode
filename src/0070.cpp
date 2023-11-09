// https://leetcode.com/problems/climbing-stairs/

// Top Down

class Solution
{
public:
  int climbStairs(int n, vector<int> &memo)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    if (memo[n])
      return memo[n];

    return memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
  }

  int climbStairs(int n)
  {
    vector<int> memo(n + 1);
    return climbStairs(n, memo);
  }
};

// Bottom Up
class Solution
{
public:
  int climbStairs(int n)
  {
    vector<int> dp(46);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};