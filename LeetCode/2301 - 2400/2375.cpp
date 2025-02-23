// 2375. Construct Smallest Number From DI String

// Solution 1 using Recursion and Greedy Backtracking
// Time Complexity: O(2^N)
// Space Complexity: O(N)
class Solution
{
public:
    string res;
    int n;
    void helper(string &pattern, string curr, int pos, bool (&used)[10])
    {
        if (pos == n + 1)
        {
            res = min(res, curr);
            return;
        }
        for (int i = 1; i < 10; i++)
        {
            if (pos > 0)
            {
                int prev = (curr.back() - '0');
                char p = pattern[pos - 1];
                if ((p == 'I' && i <= prev) || (p == 'D' && i >= prev))
                    continue;
            }
            if (!used[i])
            {
                used[i] = true;
                curr.push_back(i + '0');
                helper(pattern, curr, pos + 1, used);
                used[i] = false;
                curr.pop_back();
            }
        }
    }
    string smallestNumber(string pattern)
    {
        n = pattern.size();
        string curr;
        bool used[10];
        memset(used, 10, false);
        res.resize(n + 1, '9');
        helper(pattern, curr, 0, used);
        return res;
    }
};

// Solution 2 using Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
    public:
        string smallestNumber(string pattern) {
            string result;
            stack<int> st;
            for (int i = 0; i <= pattern.size(); i++) {
                st.push(i + 1);
                if (i == pattern.size() || pattern[i] == 'I') {
                    while (!st.empty()) {
                        result += (st.top() + '0');  
                        st.pop();
                    }
                }
            }
            return result;
        }
    };
    