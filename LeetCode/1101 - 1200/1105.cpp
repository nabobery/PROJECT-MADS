// 1105. Filling Bookcase Shelves

// Solution 1 using Recursion + Memoization
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int n;
    int helper(vector<vector<int>>& books, int ind, vector<int>& dp, int& shelfWidth){
        // Base case
        if(ind >= n) return 0;
        // Memoization check
        if(dp[ind] != -1) return dp[ind];
        int currw = 0, currh = 0, res = INT_MAX;
        // go on adding books from ind to n-1 and calculate the height
        for(int i = ind; i < n;i++){
            // if the current width is less than or equal to shelfWidth, then add the book
            currw += books[i][0];
            if(currw <= shelfWidth){
                // update the current height
                currh = max(books[i][1], currh);
                // update the result with the minimum height by adding the current height and the height of the remaining books
                res = min(res, currh + helper(books, i+1, dp, shelfWidth));
            }
            else break;
        }
        // Memoize the result
        return dp[ind]=res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        vector<int> dp(n, -1);
        return helper(books, 0, dp, shelfWidth);
    }
};

// Solution 2 using Tabulation
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int currw = 0, currh = 0;
            for(int j = i-1; j >= 0; j--){
                currw += books[j][0];
                if(currw > shelfWidth) break;
                currh = max(currh, books[j][1]);
                dp[i] = min(dp[i], dp[j] + currh);
            }
        }
        return dp[n];
    }
};