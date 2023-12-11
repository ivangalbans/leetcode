// https://leetcode.com/problems/count-complete-substrings/description/

class Solution
{
public:
    int countCompleteSubstrings(const string &s, int len, int k)
    {
        int freq[26] = {};
        int exact = 0, count = 0;
        for (int l = 0, r = 0; r < s.length(); ++r)
        {
            if (r && abs(s[r] - s[r - 1]) > 2)
            {
                memset(freq, 0, sizeof(freq));
                exact = 0;
                l = r;
            }
            int reps = ++freq[s[r] - 'a'];
            exact += (reps == k) ? 1 : 0;

            if (r - l + 1 == len)
            {
                count += (exact * k == len);
            }
            else if (r - l + 1 == len + 1)
            {
                reps = --freq[s[l++] - 'a'];
                exact += ((reps == k - 1) ? -1 : 0);
                count += (exact * k == len);
            }
        }

        return count;
    }
    int countCompleteSubstrings(string word, int k)
    {
        int ans = 0;
        for (int len = k; len <= 26 * k; len += k)
            ans += countCompleteSubstrings(word, len, k);
        return ans;
    }
};