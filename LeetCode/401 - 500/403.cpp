// 403. Frog Jump

// Solution 1: Recursion TLE
class Solution {
public:
    bool helper(vector<int>& stones, int i, int k){
        if(i == stones.size()-1) return true;
        bool f = false;
        for(int j = i+1; j < stones.size();j++){
            if(stones[i]+k-1 == stones[j]){
                f |=  helper(stones, j, k-1);
            }
            if(f) break;
            if(stones[i]+k == stones[j]){
                f |= helper(stones,j, k);
            }
            if(f) break;
            if(stones[i]+k+1 == stones[j]){
                f |= helper(stones, j, k+1);
            }
            if(f) break;
        }
        return f;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        return helper(stones, 0, 1);
    }
};

// Solution 2: Recursion + Memoization + Smart Jump (Top down)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    unordered_map<int,int> mp;
    int dp[2001][2001];
    int helper(vector<int>& stones, int n, int i, int k){
        // if we are at last stone then return true
        if(i == n-1) return 1;
        // if dp[i][k] is not -1 then return dp[i][k]
        if(dp[i][k] != -1) return dp[i][k];
        // check if we can jump to next stone with k-1, k, k+1 jump size
        bool f = false;
        for(int j = k-1; j <= k+1;j++){
            // if j is greater than 0 and we have stone with value stones[i]+j then call helper function
            if(j > 0 && mp.count(stones[i]+j)){
                // if helper function return true then take or operation with f
                f |= helper(stones, n, mp[stones[i] + j], j);
            }
        }
        // return dp[i][k] = f
        return dp[i][k] = f;
    }
    bool canCross(vector<int>& stones) {
        // map to store stone value and index of stones
        for(int i = 0; i < stones.size();i++) mp.insert({stones[i], i});
        // initialize dp array
        memset(dp, -1, sizeof(dp));
        // return helper function by passing stones, size of stones, index of stone, and jump size
        return helper(stones, stones.size(), 0, 0);
    }
};

// Solution 3: DP (Bottom up)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    int dp[2001][2001];
    bool canCross(vector<int>& stones) {
        // map to store stone value and index of stones
        unordered_map<int,int> mp;
        for(int i = 0; i < stones.size();i++) mp.insert({stones[i], i});
        // set dp[0][0] = true
        dp[0][0] = true;
        // iterate for all stones
        for(int i = 0; i < stones.size();i++){
            for(int k = 0; k <= stones.size();k++){
                // if dp[i][k] is true then check if we can jump to next stone with k-1, k, k+1 jump size
                if(dp[i][k]){
                    for(int j = k-1; j <= k+1;j++){
                        // if j is greater than 0 and we have stone with value stones[i]+j then set dp[mp[stones[i]+j]][j] = true
                        if(j > 0 && mp.count(stones[i]+j)){
                            dp[mp[stones[i]+j]][j] = true;
                        }
                    }
                }
            }
        }
        // iterate for last stone
        for(int i = 0; i < stones.size();i++){
            // if dp[stones.size()-1][i] is true then set res = true
            if(dp[stones.size()-1][i]) return true;
        }
        // return res
        return false;
    }
};

// Solution 4: DP + Binary Search (Bottom up)
class Solution {
public:
    int dp[2001][2001];
    bool helper(vector<int>& stones, int i, int k){
        if(i == stones.size()-1) return 1;
        if(dp[i][k] != -1) return dp[i][k];
        bool f = false;
        int mi = max(1, k-1), ma = k+1;
        int ind1 = lower_bound(stones.begin(), stones.end(), stones[i] + mi) - stones.begin();
        int ind2 = upper_bound(stones.begin(), stones.end(), stones[i] + ma) - stones.begin();
        for(int j = ind1; j < ind2;j++) f |= helper(stones,j, stones[j] - stones[i]);
        return dp[i][k] = f;
    }
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return helper(stones, 0, 0);
    }
};