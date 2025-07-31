// 2210. Count Hills and Valleys in an Array

// Solution 1: Using Two-Pointer Technique
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), res= 0;
        for(int i = 1; i < n-1;i++){
            if(nums[i-1] < nums[i]){
                int j;
                bool hill = false;
                for(j = i+1; j < n;j++){
                    if(nums[i] == nums[j]) continue;
                    if(nums[j] > nums[i]) break;
                    hill = true;
                    break;
                }
                if(hill) res++;
                i = j-1;
            }
            else if(nums[i-1] >  nums[i]){
                int j;
                bool valley = false;
                for(j = i+1; j < n;j++){
                    if(nums[i] == nums[j]) continue;
                    if(nums[j] < nums[i]) break;
                    valley = true;
                    break;
                }
                if(valley) res++;
                i = j-1;
            }
        }
        return res;
    }
};