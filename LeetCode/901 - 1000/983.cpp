// 983. Minimum Cost For Tickets

// Solution 1: Using Recursion and Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int helper(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (ind == days.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int cost1 = costs[0] + helper(findNextDay(ind, days, 1), days, costs, dp);
        int cost2 = costs[1] + helper(findNextDay(ind, days, 7), days, costs, dp);
        int cost3 = costs[2] + helper(findNextDay(ind, days, 30), days, costs, dp);
        return dp[ind] = min({cost1, cost2, cost3});
    }

    int findNextDay(int ind, vector<int>& days, int duration) {
        int nextDay = days[ind] + duration - 1;  
        while (ind < days.size() && days[ind] <= nextDay) {
            ind++;
        }
        return ind;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);  
        return helper(0, days, costs, dp);  
    }
};

// Solution 2: Using Dynamic Programming Iterative
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, 0);
        for (int i = days.size() - 1; i >= 0; i--) {
            int cost1 = costs[0] + dp[findNextDay(i, days, 1)];
            int cost2 = costs[1] + dp[findNextDay(i, days, 7)];
            int cost3 = costs[2] + dp[findNextDay(i, days, 30)];
            dp[i] = min({cost1, cost2, cost3});
        }
        return dp[0];
    }

    int findNextDay(int ind, vector<int>& days, int duration) {
        int nextDay = days[ind] + duration - 1;  
        while (ind < days.size() && days[ind] <= nextDay) {
            ind++;
        }
        return ind;
    }
};