// 3174. Clear Digits

// Solution 1: Using stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    string clearDigits(string s)
    {
        string res;
        stack<char> stk;
        for (char &ch : s)
        {
            if (ch >= '0' && ch <= '9')
                stk.pop();
            else
                stk.push(ch);
        }
        while (!stk.empty())
        {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};