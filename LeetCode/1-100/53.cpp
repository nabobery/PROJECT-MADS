// 53. Maximum Subarray
// Not efficient using Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_max = 0, max = INT_MIN;
        for(int i = 0; i < n; i++){
            curr_max += nums[i];
            if(max < curr_max){
                max = curr_max;
            }
            if(curr_max < 0){
                curr_max = 0;
            }
        }
        return max;
    }
};