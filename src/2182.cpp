// https://leetcode.com/problems/construct-string-with-repeat-limit/

class Solution {
public:
  int findDiff(string &s, int l, int r) {
    for (int i = r; i < s.length(); ++i)
      if (s[i] != s[l])
        return i;
    return -1;
  }
  void mySort(string &s) {
    vector<int> alpha(26);
    for (auto ch : s)
      alpha[ch - 'a']++;

    int ind = 0;
    for (char ch = 'z'; ch >= 'a'; --ch)
      while (alpha[ch - 'a']--)
        s[ind++] = ch;
  }
  string repeatLimitedString(string s, int repeatLimit) {
    mySort(s);

    int c = 1, l = 1, r = 2;
    for (l = 1; l < s.length(); ++l) {
      c = s[l] == s[l - 1] ? c + 1 : 1;

      if (c > repeatLimit) {
        r = findDiff(s, l, max(l + 1, r));
        if (r == -1)
          break;
        else
          swap(s[l], s[r]), c = 1;
      }
    }

    return string(s, 0, l);
  }
};
