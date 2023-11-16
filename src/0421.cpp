// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

bool solve(string &s, unordered_set<string> &dic, unordered_map<string, bool> &memo)
{
    struct Trie
    {
        struct node
        {
            node *edge[2];

            node() { memset(edge, 0, sizeof(edge)); }
        } *root;

        Trie() { root = new node(); }

        void insert(int num)
        {
            node *t = root;
            for (int i = 31; i >= 0; --i)
            {
                int pos = (num & (1 << i)) ? 1 : 0;
                if (!t->edge[pos])
                    t->edge[pos] = new node();
                t = t->edge[pos];
            }
        }

        int max_xor(int num)
        {
            node *t = root;
            int ans = 0;
            for (int i = 31; i >= 0; --i)
            {
                int pos = (num & (1 << i)) ? 0 : 1;
                if (t->edge[pos])
                {
                    ans |= (1 << i);
                    t = t->edge[pos];
                }
                else
                {
                    t = t->edge[1 - pos];
                }
            }
            return ans;
        }
    };

    class Solution
    {
    public:
        int findMaximumXOR(vector<int> &nums)
        {
            Trie trie;
            int ans = 0;
            for (auto num : nums)
            {
                trie.insert(num);
                ans = max(ans, trie.max_xor(num));
            }

            return ans;
        }
    };