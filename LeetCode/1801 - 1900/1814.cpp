// 1814. Count Nice Pairs in an Array

// Solution 1 using HashMap and some inbuilt functions
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int mod = 1e9+7;
    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num - rev(num)]++;
        }
        long long res = 0, temp;
        for(auto it : mp){
            temp = it.second;
            temp *= (it.second-1);
            temp /= 2;
            res += temp%mod;
            res %= mod;
        }
        return res;
    }
};


// A better Solution 1 without using inbuilt functions
class Solution {
public:
    int mod = 1e9+7;
    int rev(int n){
        int res = 0;
        while(n){
            res *= 10;
            res += n%10;
            n /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num - rev(num)]++;
        }
        long long res = 0, temp;
        for(auto it : mp){
            temp = it.second;
            temp *= (it.second-1);
            temp /= 2;
            res += temp%mod;
            res %= mod;
        }
        return res;
    }
};

