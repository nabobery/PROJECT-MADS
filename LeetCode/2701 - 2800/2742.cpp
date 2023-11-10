// 2742. Painting the Walls

// Top Down DP
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution {
public:
    // dp[i][j] = min cost to paint walls from i to n with j time remaining
    vector<vector<int>> dp;
    // n = number of walls
    int n;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // n = number of walls
        n = cost.size();
        // dp[i][j] = min cost to paint walls from i to n with j time remaining
        dp.resize(n, vector<int>(n+1, -1));
        // return min cost to paint walls from 0 to n with n time remaining
        return solve(0, n, cost, time);
    }
    int solve(int i, int remain, vector<int>& cost, vector<int>& time) {
        // if no time remaining, then we'll have 0 cost as we cant paint any wall
        if(remain <= 0) return 0;
        // if no walls remaining, return some high value
        if(i == n) return 1e9;
        // if already calculated, return dp[i][remain]
        if(dp[i][remain] != -1) return dp[i][remain];
        // paint = cost of painting current wall by the paid painter + min cost to paint remaining walls with remaining time
        // time[i] = time taken to paint current wall by the paid painter
        // 1 = time taken to paint the wall by the free painter
        int paint = cost[i] + solve(i+1, remain-1-time[i], cost, time);
        // dontPaint = min cost to paint remaining walls with remaining time
        int dontPaint = solve(i+1, remain, cost, time);
        // return dp[i][remain] = min(paint, dontPaint)
        return dp[i][remain] = min(paint, dontPaint);
    }
};


// Bottom Up DP
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // dp[i][j] = min cost to paint walls from i to n with j time remaining
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // if no walls remaining, return some high value
        for(int i = 1; i <= n; i++) 
            dp[n][i] = 1e9;
        // go from the last wall to the first wall
        for(int i = n-1; i >= 0;i--){
            // go from 0 to n time remaining
            for(int remain = 1; remain <= n;remain++){
                // paint = cost of painting current wall by the paid painter + min cost to paint remaining walls with remaining time
                int paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];
                // dontPaint = min cost to paint remaining walls with remaining time
                int dontPaint = dp[i + 1][remain];
                // return dp[i][remain] = min(paint, dontPaint)
                dp[i][remain] = min(paint, dontPaint);
            }
        }
        // return min cost to paint walls from 0 to n with n time remaining
        return dp[0][n];
    }
};


// Space Optimized Bottom Up DP
// Time Complexity: O(N^2)
// Space Complexity: O(N)
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // dp[i] = min cost to paint n walls with i time remaining
        vector<int> dp(n+1, 0);
        // if no walls remaining, return some high value
        vector<int> prevdp(n+1, 1e9);
        prevdp[0] = 0;
        for(int i = n-1; i >= 0;i--){
            for(int j = 1; j <= n;j++){
                // paint = cost of painting current wall by the paid painter + min cost to paint remaining walls with remaining time
                int paint = cost[i] + prevdp[max(0, j - 1 - time[i])];
                // dontPaint = min cost to paint remaining walls with remaining time
                int dontPaint = prevdp[j];
                // return dp[i][remain] = min(paint, dontPaint)
                dp[j] = min(paint, dontPaint);
            }
            prevdp = dp;
        }
        // return min cost to paint walls from 0 to n with n time remaining
        return dp[n];
    }
};




    

