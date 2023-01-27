class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> mk(26);
        for (auto ch : sentence)
            mk[ch - 'a'] = 1;
        return accumulate(begin(mk), end(mk), 0) == 26;
    }
};