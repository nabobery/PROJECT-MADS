// 279. Perfect Squares

// O(n*sqrt(n)) time complexity and O(n) space complexity DP Solution
class Solution
{
public:
    int numSquares(int n)
    {
        // dp[i] represents the minimum number of perfect squares that sum to i
        vector<int> dp(n + 1, INT_MAX);
        // if n is a perfect square then we need only one perfect square to sum to n
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // if n is not a perfect square then we need to sum to n using perfect squares less than n
            // so we need to find the minimum number of perfect squares that sum to n
            // dp[i] = min(dp[i], dp[i-j*j]+1) where j*j <= i
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// Efficient Brute Force Solution using Mathematics (Lagrange's Four Square Theorem & Legendre's Three Square Theorem)
// O(sqrt(n)) time complexity and O(1) space complexity
class Solution
{
public:
    int numSquares(int n)
    {
        // if n is a perfect square then we need only one perfect square to sum to n
        if (isPerfectSquare(n))
            return 1;
        // We need to check if n is of the form of sum of 2 perfect squares
        for (int i = 1; i * i <= n; i++)
        {
            if (isPerfectSquare(n - i * i))
                return 2;
        }
        // if n is of the form 4^k*(8*m+7) then n can not be represented as sum of 3 perfect squares
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 != 7)
            return 3;
        // if n is of the form 4^k*(8*m+7) then n can be represented as sum of 4 perfect squares
        return 4;
    }

private:
    bool isPerfectSquare(int n)
    {
        int root = sqrt(n);
        return root * root == n;
    }
};