// 712. Minimum ASCII Delete Sum for Two Strings

// Solution 1: Using Top-Down Dynamic Programming (Memoization)
// Time Complexity: O(m * n), where m and n are the lengths of s1 and s2 respectively.
// Space Complexity: O(m * n) for the memoization table.
class Solution {
public:
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i >= s1.size() || j >= s2.size()){
            int left = 0;
            for(int ind = i; ind < s1.size();ind++) left += s1[ind];
            for(int ind = j; ind < s2.size();ind++) left += s2[ind];
            return left;
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int res = INT_MAX;
        if(s1[i] == s2[j]) res = helper(i+1, j+1, s1, s2, dp);
        else{
            res = min(res, s1[i] + helper(i+1, j, s1, s2, dp));
            res = min(res, s2[j] + helper(i, j+1, s1, s2, dp));
        }
        return dp[i][j] = res;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        return helper(0, 0, s1, s2, dp);
    }
};

// Solution 2: Using Bottom-Up Dynamic Programming
// Time Complexity: O(m * n), where m and n are the lengths of s1 and s2 respectively.
// Space Complexity: O(m * n) for the DP table.
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        // DP table where dp[i][j] represents the minimum ASCII delete sum to make s1[i:] and s2[j:] equal
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Fill the last row and last column (base case)
        for(int i = n-1; i >= 0; i--){
            dp[i][m] = dp[i+1][m] + s1[i];
        }
        for(int j = m-1; j >= 0; j--){
            dp[n][j] = dp[n][j+1] + s2[j];
        }
        // Fill the DP table
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                // If characters are equal, move to the next characters
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                // If characters are not equal, consider deleting from either s1 or s2
                } else {
                    dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }   
};

// Solution 3: Space Optimized Bottom-Up Dynamic Programming
// Time Complexity: O(m * n), where m and n are the lengths of s1 and s2 respectively.
// Space Complexity: O(n), where n is the length of s2.
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        // DP array to store the minimum ASCII delete sum for s2
        vector<int> dp(m + 1, 0);
        // Initialize the base case for dp array
        // Fill dp for the case when s1 is empty
        for (int j = 1; j <= m; ++j) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }
        // Fill the dp array for each character in s1
        for (int i = 1; i <= n; ++i) {
            // Update dp[0] for the case when s2 is empty
            int prev = dp[0];
            dp[0] += s1[i - 1];
            // Update the dp array for each character in s2
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                // If characters are equal, take the diagonal value
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;
                // If characters are not equal, consider deleting from either s1 or s2
                } else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }
                // Update prev for the next iteration
                prev = temp;
            }
        }
        // The last element of dp array contains the result
        return dp[m];
    }
};