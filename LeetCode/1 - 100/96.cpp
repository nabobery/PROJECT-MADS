// C++ code to find number of unique BSTs

// O(n^2) Time and O(1) space recursion + memoisation solution
class Solution {
public:
    int dp[20] = {};
    int helper(int n){
        if(n <=  1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n;i++){
            dp[n] += helper(n-i) * helper(i-1);
        }
        return dp[n];
    }
    int numTrees(int n) {
        return helper(n);
    }
};


// O(n^2) Time and O(n) space Dynamic Programming solution
class Solution {
public:
    int numTrees(int n) {
		// dp[i] stores the number of unique BSTs for i nodes
        vector<int> dp(n+1,0);
		// Base cases
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
			// dp[i] = sum of (dp[j-1] * dp[i-j]) for all j
            for (int j = 1; j <= i; j++) {
				// dp[j-1] * dp[i-j] is the number of unique BSTs for j-1 nodes on the left and i-j nodes on the right and j as the root
                dp[i] += (dp[i - j] * dp[j - 1]);
            }
	    }
	    return dp[n];
    }
};

// O(n) Time and O(1) space Catalan Number solution
// Catalan Number(n) = 1/n+1 2nCn = (2n)! / (n+1)!n! =  (2n)! / (n+1)n!n!
class Solution {
public:
	int numTrees(int n) {
		long long int ans = 1;
		for(int i = 1; i <= n; i++){
			ans = ans * (n+i) / i;
		}
		return ans / (n+1);
	}
};

