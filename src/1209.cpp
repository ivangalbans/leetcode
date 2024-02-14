// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

// Stack

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<int, char>> freq;

        for (auto ch : s)
        {
            if (!freq.empty() && freq.top().second == ch)
            {
                if (freq.top().first == k - 1)
                {
                    while (!freq.empty() && freq.top().second == ch)
                        freq.pop();
                }
                else
                {
                    freq.push({freq.top().first + 1, ch});
                }
            }
            else
            {
                freq.push({1, ch});
            }
        }

        string ans(freq.size(), '-1');
        for (int i = ans.size() - 1; i >= 0; --i)
        {
            ans[i] = freq.top().second;
            freq.pop();
        }

        return ans;
    }
};

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();
        string ans = s;
        vector<int> cnt(n);
        int i = 0;
        for (int j = 0; j < s.length(); ++j, ++i)
        {
            ans[i] = s[j];
            cnt[i] = i > 0 && ans[i] == ans[i - 1] ? cnt[i - 1] + 1 : 1;
            if (cnt[i] == k)
                i -= k;
        }
        return ans.substr(0, i);
    }
};