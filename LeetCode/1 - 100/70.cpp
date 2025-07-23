// 70. Climbing Stairs

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int t0 = 1, t1 = 1, temp;
        for (int i = 2; i <= n; i++)
        {
            temp = t1;
            t1 += t0;
            t0 = temp;
        }
        return t1;
    }
};