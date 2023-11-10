// 2366. Minimum Replacements to Sort the Array

// Solution 1: O(n) in time, O(1) in space
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size(), ma = nums[n-1];
        long long result = 0;
        for(int i = n-2; i >= 0;i--){
            if(nums[i] > nums[i+1]){
                long long num = nums[i]/nums[i+1] + (nums[i]%nums[i+1] != 0);
                // long long num = ceil((nums[i] + nums[i+1] - 1LL)/nums[i+1]);
                result += num - 1;
                nums[i] = nums[i]/num;
            }
        }
        return result;
    }
};