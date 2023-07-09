// 509. Fibonacci Number

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        int t0 = 0, t1 = 1;
        for (int i = 2; i <= n; i++)
        {
            t1 += t0;
            t0 = t1 - t0;
        }
        return t1;
    }
};