// https://leetcode.com/problems/happy-number/description/

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = square_sum(slow);
            fast = square_sum(square_sum(fast));
        } while (slow != fast);

        return slow == 1;
    }

    int square_sum(int n)
    {
        int sum = 0;
        while (n)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};