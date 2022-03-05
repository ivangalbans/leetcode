// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/

class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int ans = 0;

    while (s.length()) {
      int i = s.find(s.back());
      if (i == s.length() - 1)
        ans += i / 2;
      else
        ans += i, s.erase(i, 1);
      s.pop_back();
    }

    return ans;
  }
};
