// 3314. Construct the Minimum Bitwise Array I

// Solution 1: Brute Force
// Time Complexity: O(n*maxNum)
// Space Complexity: O(1)
class Solution {
public:
    int helper(int num){
        for(int i = 1; i < num;i++){
            if((i | (i+1)) == num) return i;
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n;i++){
            res[i] = helper(nums[i]);
        }
        return res; 
    }
};