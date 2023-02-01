class Solution {
public:

    string longestDiverseString(int a, int b, int c, char ca, char cb, char cc) {
        if(a < b)  return longestDiverseString(b, a, c, cb, ca, cc);
        if(b < c)  return longestDiverseString(a, c, b, ca, cc, cb);
        if(b == 0) return string(min(2, a), ca);

        int na = min(2, a);
        int nb = a - na >= b ? 1 : 0;

        return string(na, ca) +  string(nb, cb) + longestDiverseString(a - na, b - nb, c, ca, cb, cc);
    }

    string longestDiverseString(int a, int b, int c) {
        return longestDiverseString(a, b, c, 'a', 'b', 'c');
    }

};
