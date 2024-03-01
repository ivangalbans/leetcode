class Solution
{
public:
    /*
    number  --> (decimal | integer) [exp]
    exp     --> ('e' | 'E') integer
    decimal --> [sign] (oneOrMoreDigits'.'[oneOrMoreDigits] | '.'oneOrMoreDigits)
    integer --> [sign] oneOrMoreDigits
    oneOrMoreDigits --> \d+
    sign    --> '+' | '-'
    */

    bool isSign(char ch)
    {
        return ch == '+' || ch == '-';
    }

    bool oneOrMoreDigits(string s)
    {
        return s != "" &&
               all_of(begin(s), end(s), [](char ch)
                      { return isdigit(ch); });
    }

    bool isInteger(string s)
    {
        if (s == "")
            return false;

        return (isSign(s[0])) ? oneOrMoreDigits(s.substr(1)) : oneOrMoreDigits(s);
    }

    bool isUnsignedDecimal(string s)
    {
        if (s == "")
            return false;

        int dot_index = find_if(begin(s), end(s), [](auto ch)
                                { return ch == '.'; }) -
                        begin(s);

        string left = s.substr(0, dot_index);
        string right = s.substr(dot_index);

        return right != "" &&
               (left == "" ? true : oneOrMoreDigits(left)) &&
               (right == "." ? left != "" : oneOrMoreDigits(right.substr(1)));
    }

    bool isDecimal(string s)
    {
        if (s == "")
            return false;

        return isSign(s[0]) ? isUnsignedDecimal(s.substr(1)) : isUnsignedDecimal(s);
    }

    bool isNumber(string s)
    {
        int e_index = find_if(begin(s), end(s), [](auto ch)
                              { return ch == 'e' || ch == 'E'; }) -
                      begin(s);

        string left = s.substr(0, e_index);
        string right = s.substr(e_index);

        return (isDecimal(left) || isInteger(left)) && (right == "" ? true : isInteger(right.substr(1)));
    }
};