// 3010. Divide an Array Into Subarrays With Minimum Cost I

// Solution 1: Simple Greedy and Straightforward
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int s1 = nums[0], s2 = 100, s3 = 100, n = nums.size();
        for(int i = 1; i < n;i++){
            if(nums[i] < s2){
                s3 = s2;
                s2 = nums[i];
            }
            else if(nums[i] < s3){
                s3 = nums[i];
            }
        }
        return (s1+s2+s3);
    }
};