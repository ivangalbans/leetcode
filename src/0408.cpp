// https://leetcode.com/problems/valid-word-abbreviation/description/

class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int n = word.length(), m = abbr.length();

        int i = 0, j = 0;
        int num;
        while (i < n && j < m)
        {
            if (word[i] == abbr[j])
            {
                ++i;
                ++j;
                continue;
            }

            if (!isdigit(abbr[j]) || abbr[j] == '0')
                return false;

            int start = j;
            while (j < m && isdigit(abbr[j]))
                j++;
            int num = stoi(abbr.substr(start, j - start));
            i += num;
        }

        return i == n && j == m;
    }
};