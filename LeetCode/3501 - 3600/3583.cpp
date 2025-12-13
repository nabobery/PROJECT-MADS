// 3583. Count Special Triplets

// Solution 1: Using Hash Map and Prefix and Suffix Counting
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long res = 0;
        unordered_map<int, int> prefixCounts, suffixCounts;
        for(int i = 0; i < n;i++) suffixCounts[nums[i]]++;
        for(int i = 0; i < n;i++){
            int target = nums[i]*2;
            suffixCounts[nums[i]]--;
            long curr = prefixCounts[target];
            curr *= suffixCounts[target];
            curr %= mod;
            res = (res+curr)% mod;
            prefixCounts[nums[i]]++;
        }
        return res;
    }
};