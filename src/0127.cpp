// https://leetcode.com/problems/word-ladder/

class Solution
{
public:
    vector<string> adj(string s, unordered_set<string> &dic)
    {
        vector<string> ans;
        for (int i = 0; i < s.length(); ++i)
        {
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (s[i] != ch)
                {
                    char tmp = s[i];
                    s[i] = ch;
                    if (dic.count(s))
                        ans.push_back(s);
                    s[i] = tmp;
                }
            }
        }
        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, int> d;

        d[beginWord] = 1;
        queue<string> q;

        unordered_set<string> dic(begin(wordList), end(wordList));

        q.push(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            for (string next : adj(word, dic))
            {
                if (d[next] == 0)
                {
                    d[next] = 1 + d[word];
                    q.push(next);
                }
            }
        }

        return d[endWord];
    }
};