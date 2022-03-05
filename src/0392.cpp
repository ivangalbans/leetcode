// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();

    int i = 0, j;
    for (int j = 0; j < m; ++j)
      if (s[i] == t[j])
        i++;

    return i == n;
  }
};
