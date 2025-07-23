// 72. Edit Distance

// O(nm) time complexity and O(nm) space complexity top down DP Solution
class Solution {
public:
    // dp[i][j] represents the minimum number of operations to convert word1[0..i) to word2[0..j)
    int dp[1001][1001]; 
    
    // helper function to calculate the minimum number of operations to convert word1[0..n) to word2[0..m)
    int helper(string &word1, string &word2, int n, int m){
        // if any of the string is empty then return the length of other string
        // if word1 is empty then we need to insert all the characters of word2
        if(n==0) return m;  
        // if word2 is empty then we need to remove all the characters of word1
        if(m==0) return n;
        // if dp[n][m] is already calculated then return it
        if(dp[n][m]!=-1) return dp[n][m];
        // if last characters of both the strings are same then we don't need to do any operation
        if(word1[n-1]==word2[m-1]) return dp[n][m]=helper(word1,word2,n-1,m-1);
        // else we need to perform one of the three operations
        // replace the last character of word1 with last character of word2
        int replace = helper(word1, word2, n - 1, m - 1);
        // insert the last character of word2 at the end of word1
        int insert = helper(word1,word2,n,m-1);
        // remove the last character of word1
        int remove=helper(word1,word2,n-1,m);
        return dp[n][m]=1+ min({replace,insert,remove});
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // initialize dp with -1
        memset(dp,-1,sizeof(dp));
        // call helper function
        return helper(word1,word2,n,m);
    }
};

// O(nm) time complexity and O(nm) space complexity bottom up DP Solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // dp[i][j] represents the minimum number of operations to convert word1[0..i) to word2[0..j)
        int dp[n+1][m+1];
        // if any of the string is empty then return the length of other string
        // if word2 is empty then we need to remove all the characters of word1
        for(int i=0;i<=n;i++) dp[i][0]=i;
        // if word1 is empty then we need to insert all the characters of word2
        for(int j=0;j<=m;j++) dp[0][j]=j;
        // if last characters of both the strings are same then we don't need to do any operation
        // else we need to perform one of the three operations
        // replace the last character of word1 with last character of word2
        // insert the last character of word2 at the end of word1
        // remove the last character of word1
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+ min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }
        return dp[n][m];
    }
};

// O(nm) time complexity and O(m) space complexity bottom up 1D DP Solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // dp[i] represents the minimum number of operations to convert word1[0..n) to word2[0..i)
        int dp[m+1];
        // if word1 is empty then we need to insert all the characters of word2
        for(int i=0;i<=m;i++) dp[i]=i;
        for(int i=1;i<=n;i++){
            // prev represents dp[i-1][j-1]
            int prev=dp[0];
            // if word2 is empty then we need to remove all the characters of word1
            dp[0]=i; // dp[i][0]=i
            // if last characters of both the strings are same then we don't need to do any operation
            // else we need to perform one of the three operations
            // replace the last character of word1 with last character of word2
            // insert the last character of word2 at the end of word1
            // remove the last character of word1
            for(int j=1;j<=m;j++){
                // temp represents dp[i-1][j]
                int temp=dp[j];
                if(word1[i-1]==word2[j-1]) dp[j]=prev;
                // dp[i][j]=1+ min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                else dp[j]=1+ min({prev,dp[j-1],dp[j]});
                // update prev
                prev=temp;
            }
        }
        return dp[m];
    }
};