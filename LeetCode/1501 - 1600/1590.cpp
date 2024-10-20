// 1590. Make Sum Divisible by P

// Solution 1: Prefix Sum + Hash Map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n;
        long prefix = 0, sum;
        unordered_map<int,int> mp;
        for(int i = 0; i < n;i++)
            prefix = prefix + nums[i];
        if(prefix % p == 0) return 0;
        sum = prefix; prefix = 0;
        mp[0] = -1;
        for(int i = 0; i < n;i++){
            prefix += nums[i];
            int needed = (prefix%p - sum%p + p) % p;
            if(mp.count(needed)) res = min(res, i - mp[needed]);
            mp[prefix%p] = i;
        }
        return res == n ? -1: res;
    }
};


