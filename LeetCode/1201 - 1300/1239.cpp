// 1239. Maximum Length of a Concatenated String with Unique Characters\

// Naive and Simple Solution Generating all possible Subsequences and checking for Max Length
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
public:
    int n, res;
    bool checkUpdate(vector<int>& temp, vector<int>& vec){
        bool b = true;
        for(int i = 0; i < 26;i++){
            temp[i] += vec[i];
            if(temp[i] > 1){
                b = false;
                break;
            }
        }
        return b;
    }
    void helper(int i, vector<vector<int>>& vec, vector<int> curr){
        if(i == n) return;
        vector<int> temp = curr;
        if(checkUpdate(temp, vec[i])){
            int cnt = 0;
            for(auto i : temp) if(i) cnt++;
            res = max(res, cnt);
            helper(i+1, vec, temp);
        }
        helper(i+1, vec, curr);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size(); res = 0;
        vector<vector<int>> vec(n, vector<int>(26,0));
        for(int i =0; i <n;i++){
            for(char ch : arr[i]) vec[i][ch - 'a']++;
        }
        vector<int> curr(26,0);
        helper(0, vec, curr);
        return res;
    }
};

// Solution 2: Using Bitmasking and DP
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(1,0);
        int res = 0;
        for(int i = 0; i < n; i++){
            int mask = 0;
            bool b = true;
            for(char ch : arr[i]){
                int bit = 1 << (ch - 'a');
                if((mask & bit) != 0){
                    b = false;
                    break;
                }
                mask |= bit;
            }
            if(!b) continue;
            for(int j = dp.size() - 1; j >= 0; j--){
                if((dp[j] & mask) != 0) continue;
                dp.push_back(dp[j] | mask);
                res = max(res, __builtin_popcount(dp.back()));
            }
        }
        return res;
    }
};