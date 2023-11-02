// 823. Binary Trees With Factors

// Solution using map and DP
// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long int> dp;
        for(auto i : arr) dp[i] = 1;
        for(auto it1: dp){
            long long int ans = dp[it1.first];
            int curr = it1.first;
            for(auto it2 : dp){
                if(curr % it2.first == 0 && dp.count(curr/it2.first)){
                   ans += dp[it2.first] *dp[curr/it2.first];
                   ans %= mod;
                }
            }
            dp[curr] = ans;
        }
        long long result = 0;
        for(auto i : dp){
            result += i.second;
            result %= mod;
        }
        return result;
    }
};

// Solution using sort, unordered_map
// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int> dp;
        for(auto i : arr) dp[i] = 1;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0 && dp.count(arr[i]/arr[j])){
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i]/arr[j]];
                    dp[arr[i]] %= mod;
                }
            }
        }
        long long result = 0;
        for(auto i : dp){
            result += i.second;
            result %= mod;
        }
        return result;
    }
};