// 2419. Longest Subarray With Maximum Bitwise AND

// Solution 1: Greedy + Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), n = nums.size(), res = 1;
        for(int i = 0; i < n;i++){
            if(nums[i] == mx){
                int j = i+1;
                while(j < n && nums[i] == nums[j]) j++;
                res = max(res, j-i);
                i = j-1;
            }
        }
        return res;
    }
};
