// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> mk(26);
        for (auto ch : s)
            mk[ch - 'a']++;

        for (auto occ : mk)
            if (occ != 0 && occ != mk[s[0] - 'a'])
                return false;

        return true;
    }
};