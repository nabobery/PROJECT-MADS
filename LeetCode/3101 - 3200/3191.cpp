// 3191. Minimum Operations to Make Binary Array Elements Equal to One I


// Solution 1: Greedy Approach 
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int res = 0, n = nums.size();
            for(int i = 0; i < n-2;i++){
                if(nums[i] == 0){
                    for(int j =i; j < i+3;j++) nums[j] = 1 - nums[j];
                    res++;
                }
            }
            if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
            return res;
        }
};