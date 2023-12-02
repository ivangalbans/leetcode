// https://leetcode.com/problems/groups-of-strings/description/

struct disjoint_set
{
    vector<int> parent, count;
    disjoint_set(int n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }
};

class Solution
{
public:
    bitset<26> to_bitset(string &s)
    {
        bitset<26> b;
        for (auto ch : s)
            b.set(ch - 'a');
        return b;
    }

    vector<int> groupStrings(vector<string> &words)
    {
        int n = words.size();
        unordered_map<bitset<26>, int> originals;
        unordered_map<bitset<26>, int> deleted_one;

        vector<bitset<26>> word_bits(n);
        for (int i = 0; i < n; ++i)
        {
            word_bits[i] = to_bitset(words[i]);
            originals[word_bits[i]] = i;
            for (int bit = 0; bit < 26; ++bit)
            {
                auto tmp = word_bits[i];
                if (tmp.test(bit))
                    deleted_one[tmp.reset(bit)] = i;
            }
        }

        disjoint_set ds(n);
        for (int i = 0; i < n; ++i)
        {
            auto w_bits = word_bits[i];
            for (int bit = 0; bit < 26; ++bit)
            {
                auto tmp = w_bits;
                tmp.flip(bit);
                if (originals.count(tmp)) // req 1 & 2
                    ds.merge(i, originals[tmp]);
                if (w_bits.test(bit) && deleted_one.count(tmp)) // req 3
                    ds.merge(i, deleted_one[tmp]);
            }
        }

        vector<int> groups(n);
        for (int i = 0; i < n; ++i)
        {
            int set_of = ds.set_of(i);
            groups[set_of] = ds.count[set_of];
        }

        int n_groups = n - count(begin(groups), end(groups), 0);
        int max_g = *max_element(begin(groups), end(groups));

        return {n_groups, max_g};
    }
};