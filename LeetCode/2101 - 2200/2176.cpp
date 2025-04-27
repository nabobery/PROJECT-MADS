// 2176. Count Equal and Divisible Pairs in an Array

// Solution 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size(), res =0;
            for(int i = 0; i < n-1;i++){
                for(int j = i+1; j < n;j++){
                    if(nums[i] == nums[j] && (i*j)%k == 0) res++;
                }
            }
            return res;
        }
};