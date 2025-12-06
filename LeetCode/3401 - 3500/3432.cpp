// 3432. Count Partitions with Even Sum Difference

// Solution 1: Simple and StraightForward
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int right = 0, left = 0, res = 0;
        for(int& num: nums) right += num;
        for(int i = 0; i < nums.size()-1;i++){
            left += nums[i];
            right -= nums[i];
            if(abs(right - left) % 2 == 0) res++;
        }
        return res;
    }
};