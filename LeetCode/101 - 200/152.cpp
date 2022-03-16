// 152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), temp;
        int curr_max = nums[0], t_max = nums[0], curr_min = nums[0];
        for(int i = 1; i < n;i++){
            temp = max({nums[i], nums[i]* curr_max, nums[i]*curr_min});
            curr_min = min({nums[i], nums[i]* curr_max, nums[i]*curr_min});
            curr_max = temp;
            t_max = max(t_max, curr_max);
        }
        return t_max;
    }
};