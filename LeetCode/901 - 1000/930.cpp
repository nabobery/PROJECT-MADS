// 930. Binary Subarrays With Sum

// Solution 1 using Prefix Sum
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0, sum = 0;
        unordered_map<int,int> mp;
        for(int num : nums){
            sum += num;
            if(sum == goal) res++;
            if(mp.count(sum - goal)) res += mp[sum-goal];
            mp[sum]++;
        }
        return res; 
    }
};
