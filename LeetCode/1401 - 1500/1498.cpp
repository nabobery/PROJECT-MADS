// 1498. Number of Subsequences That Satisfy the Given Sum Condition

// Solution 1: using Binary Search and Fast Exponentiation
// Time Complexity: O(n log n)  
// Space Complexity: O(1)
class Solution {
public:
    const int mod = 1e9 + 7;
    long fastPow(long base, long exp){
        long res = 1;
        base %= mod;
        while(exp > 0){
            if(exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long res = 0;
        for(int i = 0; i < n;i++){
            int d = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - (nums.begin() + i);
            res = (res + fastPow(2, d-1) - 1) % mod;
            if(nums[i]*2 <= target) res = (res + 1) % mod;
        }
        return res;
    }
};