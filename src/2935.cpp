// https://leetcode.com/problems/maximum-strong-pair-xor-ii/description/

struct Trie
{

    struct node
    {
        int partial;
        node *edge[2];
        node() : partial(0) { memset(edge, 0, sizeof(edge)); }
    } *root;

    Trie() { root = new node(); }

    void insert(int num)
    {
        node *t = root;
        for (int i = 20; i >= 0; --i)
        {
            int pos = (num & (1 << i)) ? 1 : 0;
            if (!t->edge[pos])
                t->edge[pos] = new node();
            t = t->edge[pos];
            t->partial++;
        }
    }

    void remove(int num)
    {
        node *t = root;
        for (int i = 20; i >= 0; --i)
        {
            int pos = (num & (1 << i)) ? 1 : 0;
            t = t->edge[pos];
            t->partial--;
        }
    }

    int search(int num)
    {
        node *t = root;
        int mask = 0;

        for (int i = 20; i >= 0; --i)
        {
            int pos = (num & (1 << i)) ? 0 : 1;
            if (t->edge[pos] && t->edge[pos]->partial)
            {
                mask |= (1 << i);
                t = t->edge[pos];
            }
            else
            {
                t = t->edge[1 - pos];
            }
        }

        return mask;
    }
};

class Solution
{
public:
    bool areStrong(int x, int y)
    {
        return abs(x - y) <= min(x, y);
    }

    int maximumStrongPairXor(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        auto it = unique(begin(nums), end(nums));
        nums.resize(it - begin(nums));

        int l = 0, ans = 0, n = nums.size();
        Trie trie;
        for (int i = 0; i < n; ++i)
        {

            while (l < i && !areStrong(nums[l], nums[i]))
                trie.remove(nums[l++]);

            trie.insert(nums[i]);
            ans = max(ans, trie.search(nums[i]));
        }

        return ans;
    }
};