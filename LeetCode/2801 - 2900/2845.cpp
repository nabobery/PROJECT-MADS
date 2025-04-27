// 2845. Count of Interesting Subarrays

// Solution 1: Using Prefix Sum and Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            long long res = 0;
            int n = nums.size();
            // Count the number of elements in nums that are congruent to k modulo
            vector<int> prefix(n+1, 0);
            for(int i = 0; i < n;i++) prefix[i+1] = prefix[i] + (nums[i] % modulo == k);
            // unordered map to store the count of k modulo elements
            unordered_map<int,int> mp;
            for(int i = 0; i <= n;i++){
                // cnti -cntj % modulo == k
                // cntj = (cnti + modulo - k) % modulo
                // then we have to see how many subarrays we have with cnti - cntj % modulo == k
                res += mp[(prefix[i] + modulo - k) % modulo];
                mp[prefix[i]%modulo]++;
            }
            return res;
        }
};