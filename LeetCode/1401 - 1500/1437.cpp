// 1437. Check If All 1's Are at Least Length K Places Away

// Solution 1: Simple Iteration
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), prev = -1;
        for(int i = 0; i < n;i++){
            if(nums[i] == 1){
                if(prev != -1){
                    if(i-prev-1 < k) return  false;
                }
                prev = i;
            }
        }   
        return true;
    }
};