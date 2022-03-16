// 238. Product of Array Except Self O(N) time and O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int begin = 1, end = 1;
        vector<int> result(n,1);
        for(int i = 0; i < n;i++){
            result[i] *= begin;
            begin *= nums[i];
            result[n-i-1] *= end;
            end *= nums[n-i-1];
        }
        return result;
    }
};