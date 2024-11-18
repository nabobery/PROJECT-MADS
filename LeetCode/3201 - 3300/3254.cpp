// 3254. Find the Power of K-Size Subarrays I

// Solution 1: Simple Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), temp;
        if(n == 1) return nums;
        vector<int> res(n-k+1, -1);
        for(int i = 0; i < n-k+1;i++){
            bool b = true;
            temp = nums[i];
            for(int j = i+1; j < i+k;j++){
                if(nums[j] != nums[j-1] + 1){
                    b = false;
                    break;
                }
                temp = max(temp, nums[j]);
            }
            if(b) res[i] = temp;
        }
        return res;
    }
};