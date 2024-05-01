// 514. Freedom Trail

// Solution 1 Brute force by checking all possible combinations (TLE)
// Time complexity: O(n!)
// Space complexity: O(n)
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return tryallCombinations(0,0,ring,key, INT_MAX);
    }

    int tryallCombinations(int ringIndex, int keyIndex, string ring, string key, int steps){
        if(keyIndex == key.size()) return 0;
        int n = ring.size();
        int m = key.size();
        int minSteps = INT_MAX;
        for(int i = 0; i < n; i++){
            if(ring[i] == key[keyIndex]){
                int diff = abs(ringIndex - i);
                int stepsToNext = min(diff, n - diff);
                minSteps = min(minSteps, stepsToNext + tryallCombinations(i, keyIndex + 1, ring, key, steps));
            }
        }
        return minSteps + 1;
    }
};

// Solution 2 using DP with memoization
// n = ring.size(), m = key.size()
// Time complexity: O(n^2 * m)
// Space complexity: O(n * m)
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return tryallCombinations(0, 0, ring, key, dp);
    }

    int tryallCombinations(int ringIndex, int keyIndex, string& ring, string& key, vector<vector<int>>& dp){
        if(keyIndex == key.size()) return 0;
        if(dp[ringIndex][keyIndex] != -1) return dp[ringIndex][keyIndex];
        int n = ring.size();
        int m = key.size();
        int minSteps = INT_MAX;
        for(int i = 0; i < n; i++){
            if(ring[i] == key[keyIndex]){
                int diff = abs(ringIndex - i);
                int stepsToNext = min(diff, n - diff);
                minSteps = min(minSteps, stepsToNext + tryallCombinations(i, keyIndex + 1, ring, key, dp));
            }
        }
        return dp[ringIndex][keyIndex] = minSteps + 1;
    }
};        
       

// Solution 3 using Bottom-up DP 
// n = ring.size(), m = key.size()
// Time complexity: O(n^2 * m)
// Space complexity: O(n * m)
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int>(m+1, INT_MAX));
        for(int i = 0; i < n; i++)
            dp[i][m] = 0;
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(ring[k] == key[i]){
                        int diff = abs(j - k);
                        int stepsToNext = min(diff, n - diff);
                        dp[j][i] = min(dp[j][i], stepsToNext + dp[k][i+1]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};

// Solution 4 using Bottom-up DP with space optimization
// n = ring.size(), m = key.size()
// Time complexity: O(n^2 * m)
// Space complexity: O(n)
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
       vector<int> prev(n ,0), curr(n, 0);
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                curr[j] = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(ring[k] == key[i]){
                        int diff = abs(j - k);
                        int stepsToNext = min(diff, n - diff);
                        curr[j] = min(curr[j], stepsToNext + prev[k]);
                    }
                }
            }
            prev = curr;
        }
        return prev[0] + m;
    }
};
