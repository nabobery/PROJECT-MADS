// 523. Continuous Subarray Sum

// Solution 1 using Prefix Sum + Hash Table
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int s = 0, n = nums.size();
        unordered_map<int,int> prefix;
        prefix[0] = 0;
        for(int i = 1; i <= n;i++){
            s += nums[i-1];
            if(!prefix.count(s%k)) prefix[s%k] = i;
            else if(i-prefix[s%k] > 1) return true;
        }
        return false;
    }
};


