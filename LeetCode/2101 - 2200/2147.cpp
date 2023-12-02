// 2147. Number of Ways to Divide a Long Corridor

// Solution 1 using Math (Combinatorics)
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        vector<int> prefix;
        int cnt = 0;
        long long res = 1;
        for(int i = 0; i < corridor.size();i++){
            if(corridor[i] == 'S'){
                prefix.push_back(i);
                cnt++;
            }
        }
        if(cnt%2 || cnt < 2) return 0;
        for(int i = 1; i < prefix.size()-1;i+=2){
            res *= (prefix[i+1] - prefix[i]);
            res %= mod;
        }
        return res;
    }
};

// Better Solution 1 without using additional space
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int cnt = 0, prev = -1;
        long long res = 1;
        for(int i = 0; i < corridor.size();i++){
            if(corridor[i] == 'S'){
                cnt++;
                if(cnt == 2){
                    prev = i;
                    cnt = 0;
                }
                else if(cnt == 1 && prev != -1){
                    res *= (i - prev);
                    res %= mod;
                }
            }
        }
        if(prev == -1 || cnt == 1) return 0;
        return res;
    }
};


// Solution 2 using Recursion + Memoization (Top Down DP) Very slow
// Time complexity: O(n)
// Space complexity: O(n)
// seat states inlcude 0, 1, 2
class Solution {
public:
    int mod = 1e9+7;
    int helper(int index, int seats, string& corridor, vector<vector<int>>& dp){
        //if we reach the end of corridor and we have 2 seats occupied then we have found a way
        // else we have not found a way to divide the corridor
        if(index == corridor.size()) return seats == 2 ? 1 : 0;
        // if we have already calculated the answer for this state then return it
        if(dp[index][seats] != -1) return dp[index][seats];
        int res = 0;
        // if we have 2 seats occupied then we can either place a partition or not based on the current state
        if(seats == 2){
            // if the current state is 'S' then we cannot place a partition here
            // and we can only move forward with 1 seat occupied
            if(corridor[index] == 'S')
                res = helper(index+1,1, corridor, dp);
            // if the current state is 'P' then we can place a partition here and move forward with 0 seats occupied or 2 seats occupied with no partition placed here
            else
                res = (helper(index+1,0, corridor, dp) + helper(index+1,2, corridor, dp))%mod;
        }
        // if we have 0 or 1 seats occupied then we have no choice but to move forward basedon state
        else{
            if(corridor[index] == 'S')
                res = helper(index+1,seats+1, corridor, dp);
            else
                res = helper(index+1,seats, corridor, dp);
        }
        // store the answer for this state and return it
        return dp[index][seats] = res;
    }
    int numberOfWays(string corridor) {
        vector<vector<int>> dp(corridor.size(), vector<int>(3, -1));
        return helper(0, 0, corridor, dp);
    }
};

// Solution 3 using Bottom Up DP
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        vector<vector<int>> dp(corridor.size()+1, vector<int>(3));
        // base cases
        dp[corridor.size()][1] = 0;
        dp[corridor.size()][1] = 0;
        dp[corridor.size()][2] = 1;
        // iterate over the corridor from right to left
        for(int i = corridor.size()-1; i >= 0;i--){
            // if the current state is 'S' 
            if(corridor[i] == 'S'){
                dp[i][0] = dp[i+1][1];
                dp[i][1] = dp[i+1][2];
                dp[i][2] = dp[i+1][1];
            }
            // if the current state is 'P' 
            else{
                dp[i][0] = dp[i+1][0];
                dp[i][1] = dp[i+1][1];
                dp[i][2] = (dp[i+1][0] + dp[i+1][2])%mod;
            }
        }
        return dp[0][0];
    }
};

// Solution 4 using Bottom Up DP (Space Optimized)
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int dp[3] = {0,0,1};
        for(auto ch : corridor){ 
            if(ch == 'S'){
                dp[0] = dp[1];
                swap(dp[1], dp[2]);
            }
            else{
                dp[2] = (dp[0] + dp[2])%mod;
            }
        }
        return dp[0];
    }
};



        