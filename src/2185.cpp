// https://leetcode.com/problems/counting-words-with-a-given-prefix/

class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int n = pref.length();
    int ans = 0;
    for (auto &w : words) {
      string temp(w, 0, n);
      if (temp == pref)
        ans++;
    }

    return ans;
  }
};
