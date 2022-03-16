/* 1413. Minimum Value to Get Positive Step by Step Sum */
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), sum = 0, minVal = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            minVal = min(minVal, sum);
        }
        int result = 1 - minVal;
        return result;
    }
};