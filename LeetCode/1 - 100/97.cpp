// 97. Interleaving String

// Solution 1: Recursion + Memoization
// Time Complexity  = O(m*n)
// Space Complexity = O(m*n)
class Solution {
public:
    // dp array to store the result of subproblems
    int dp[101][101];
    // helper function to check if s3 is interleaving of s1 and s2
    int helper(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        // if p1, p2 and p3 are less than 0 then return true as we have reached the end of s1, s2 and s3 without any mismatch
        if(p1 < 0 && p2 < 0 && p3 < 0) return true;
        // if p1, p2 and p3 are greater than 0 and dp[p1][p2] is not -1 then return dp[p1][p2]
        if((p1 >= 0 && p2 >= 0 && p3 >= 0) && dp[p1][p2] != -1) return dp[p1][p2];
        // if p1 and p2 are greater than 0 and s1[p1] == s3[p3] and s2[p2] == s3[p3] then return dp[p1][p2] = (helper(s1,s2,s3,p1-1,p2,p3-1) || helper(s1,s2,s3,p1,p2-1,p3-1))
        // as we can choose any of the two characters from s1 and s2
        if((p1 >= 0 && s1[p1] == s3[p3]) && (p2 >= 0 && s2[p2] == s3[p3]))
            return dp[p1][p2] = (helper(s1,s2,s3,p1-1,p2,p3-1) || helper(s1,s2,s3,p1,p2-1,p3-1));
        // if s1[p1] == s3[p3] then we need to check if s1[0...p1-1] and s3[0...p2] are interleaving or not with s3[0..p3-1]
        else if(p1 >= 0 && s1[p1] == s3[p3]) return helper(s1,s2,s3,p1-1,p2,p3-1);    
        // if s2[p2] == s3[p3] then we need to check if s2[0...p2-1] and s1[0...p1] are interleaving or not with s3[0..p3-1]
        else if(p2 >= 0 && s2[p2] == s3[p3]) return helper(s1,s2,s3,p1,p2-1,p3-1);
        // if there is a mismatch then return false
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // if s3 is not equal to s1 + s2 then return false
        if(s3.size() != (s1.size() + s2.size())) return false;
        // initialize dp array with -1
        memset(dp, -1, sizeof(dp));
        // call helper function with s1, s2, s3 and their last index
        return helper(s1,s2,s3,s1.size()-1, s2.size()-1, s3.size()-1);
    }
};

// Solution 2: Bottom-Up DP
// Time Complexity  = O(m*n)
// Space Complexity = O(m*n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // if s3 size is not equal to s1 + s2 size then return false
        if(s3.size() != (s1.size() + s2.size())) return false;
        // dp array to store the result of subproblems
        // dp[i][j] = true if s1[0...i-1] and s2[0...j-1] are interleaving with s3[0...i+j-1]
        bool dp[s1.size()+1][s2.size()+1];
        // initialize dp array with false
        memset(dp, false, sizeof(dp));
        // fill the first row and first column of dp array
        for(int i = 0; i <= s1.size(); i++){
            for(int j = 0; j <= s2.size(); j++){
                // if i and j are 0 then dp[i][j] = true base case
                if(i == 0 && j == 0) dp[i][j] = true;
                // if i is 0 then dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1]
                else if(i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                // if j is 0 then dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1]
                else if(j == 0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                // if s1[i-1] == s3[i+j-1] and s2[j-1] == s3[i+j-1] then dp[i][j] = dp[i-1][j] || dp[i][j-1]
                else dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        // return dp[s1.size()][s2.size()]
        return dp[s1.size()][s2.size()];
    }
};

// Solution 3: Bottom-Up DP (Space Optimized)
// Time Complexity  = O(m*n)
// Space Complexity = O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // if s3 size is not equal to s1 + s2 size then return false
        if(s3.size() != (s1.size() + s2.size())) return false;
        // dp array to store the result of subproblems
        // dp[j] = true if s1[0...i-1] and s2[0...j-1] are interleaving with s3[0...i+j-1]
        bool dp[s2.size()+1];
        // initialize dp array with false
        memset(dp, false, sizeof(dp));
        // fill the first row of dp array
        for(int i = 0; i <= s1.size(); i++){
            for(int j = 0; j <= s2.size(); j++){
                // if i and j are 0 then dp[i][j] = true base case
                if(i == 0 && j == 0) dp[j] = true;
                // if i is 0 then dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1]
                else if(i == 0) dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1];
                // if j is 0 then dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1]
                else if(j == 0) dp[j] = dp[j] && s1[i-1] == s3[i+j-1];
                // if s1[i-1] == s3[i+j-1] and s2[j-1] == s3[i+j-1] then dp[i][j] = dp[i-1][j] || dp[i][j-1]
                else dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        // return dp[s2.size()]
        return dp[s2.size()];
    }
};