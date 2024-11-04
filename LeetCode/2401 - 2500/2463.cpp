// 2463. Minimum Total Distance Traveled

// Solution 1: Recurison -> TLE
// Time Complexity: O(n^2*m)
// Space Complexity: O(n + m)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> flattenedFactory;
        for(auto& f : factory)
            for(int i = 0; i < f[1];i++) flattenedFactory.push_back(f[0]);
        return helper(0, 0, robot, flattenedFactory);
    }
    long long helper(int ridx, int fidx, vector<int>& robot, vector<int>& flattenedFactory){
        if(ridx == robot.size()) return 0;
        if(fidx == flattenedFactory.size()) return 1e12;
        // skip the given factory
        long long res = helper(ridx, fidx+1, robot, flattenedFactory);
        // don't skip 
        res = min(res, abs(robot[ridx] - flattenedFactory[fidx]) + helper(ridx+1, fidx+1, robot, flattenedFactory));
        return res;
    }
};

// Solution 2: Recurison with memoization
// Time Complexity: O(n^2*m)
// Space Complexity: O(n*m)
class Solution {
public:
    vector<vector<long long>> dp;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> flattenedFactory;
        for(auto& f : factory)
            for(int i = 0; i < f[1];i++) flattenedFactory.push_back(f[0]);
        dp.resize(robot.size(), vector<long long>(flattenedFactory.size(), -1));
        return helper(0, 0, robot, flattenedFactory);
    }
    long long helper(int ridx, int fidx, vector<int>& robot, vector<int>& flattenedFactory){
        if(ridx == robot.size()) return 0;
        if(fidx == flattenedFactory.size()) return 1e12;
        if(dp[ridx][fidx] != -1) return dp[ridx][fidx];
        // skip the given factory
        long long res = helper(ridx, fidx+1, robot, flattenedFactory);
        // don't skip 
        res = min(res, abs(robot[ridx] - flattenedFactory[fidx]) + helper(ridx+1, fidx+1, robot, flattenedFactory));
        return dp[ridx][fidx] = res;
    }
};

// Solution 3: Iterative DP (Tabulation)
// Time Complexity: O(n^2*m)
// Space Complexity: O(n*m)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> flattenedFactory;
        for(auto& f : factory)
            for(int i = 0; i < f[1];i++) flattenedFactory.push_back(f[0]);
        int n = robot.size(), m = flattenedFactory.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        for(int i =0; i < n; i++) dp[i][m] = 1e12;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                dp[i][j] = min(dp[i][j+1], abs(robot[i] - flattenedFactory[j]) + dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Solution 4: Iterative DP (Tabulation) with space optimization
// Time Complexity: O(n^2*m)
// Space Complexity: O(m)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> flattenedFactory;
        for(auto& f : factory)
            for(int i = 0; i < f[1];i++) flattenedFactory.push_back(f[0]);
        int n = robot.size(), m = flattenedFactory.size();
        vector<long long> dp(m+1, 0), temp(m+1, 0);
        for(int i = n-1; i >= 0; i--){
            if(i != n-1) dp[m] = 1e12;
            temp[m] = 1e12;
            for(int j = m-1; j >= 0; j--){
                temp[j] = min(temp[j+1], abs(robot[i] - flattenedFactory[j]) + dp[j+1]);
            }
            dp = temp;
        }
        return dp[0];
    }
};


