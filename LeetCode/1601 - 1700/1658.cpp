// 1658. Minimum Operations to Reduce X to Zero

// Solution 1 using Sliding Window and finding longest subarray with sum sum(nums) - x so that we can get minimum operations to reduce x to zero
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, l = 0, r = 0, result = -1;
        // sum(nums) - x
        for(auto i : nums) sum += i;
        x = sum-x;
        sum =0;
        // find longest subarray with sum x
        for(;l < n && r < n;r++){
            // add elements to right
            sum += nums[r];
            // if sum > x then remove elements from left
            while(l < n && sum > x) sum -= nums[l++];
            // if sum == x then update result
            if(sum == x) result = max(result, r-l+1);
        }
        // if result == -1 then no subarray found
        // else return n - result
        return (result != -1 ? n-result : result);
    }
};

// Solution 2 using unordered_map to store sum and index of sum so that we can find longest subarray with sum sum(nums) - x
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, result = -1;
        // sum(nums) - x
        for(auto i : nums) sum += i;
        x = sum-x;
        // if sum(nums) == x then return n
        if(x == 0) return n;
        // unordered_map to store sum and index of sum
        unordered_map<int, int> mp;
        // base case when sum = 0
        mp[0] = -1;
        sum = 0;
        for(int i = 0;i < n;i++){
            // add elements to sum
            sum += nums[i];
            // if we can find original x in map then update result
            if(mp.count(sum-x)) result = max(result, i-mp[sum-x]);
            mp[sum] = i;
        }
        // if result == -1 then no subarray found
        // else return n - result
        return (result != -1 ? n-result : result);
    }
};