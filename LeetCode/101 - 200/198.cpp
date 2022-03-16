// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int result;
        int n = nums.size();
        if(n == 0)
            return 0;
        int val1 = nums[0];
        if(n == 1)
            return val1;
        int val2 = max(nums[0], nums[1]);
        if(n == 2)
            return val2;
        for(int i = 2; i < n; i++){
            result = max(nums[i] + val1, val2);
            val1 = val2;
            val2 = result;
        }
        return result;
    }
};