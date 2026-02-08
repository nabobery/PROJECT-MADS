// 3637. Trionic Array I

// Solution 1: Using State Machine
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0, n = nums.size(), q = n-1;
        if(nums[1] <= nums[0]) return false;
        for(int i = 1; i < n-1;i++){
            if(state == 0){
                if(nums[i+1] > nums[i]) continue;
                else if(nums[i+1] < nums[i]){
                    state = 1;
                }
                else return false;
            }
            else if(state == 1){
                if(nums[i+1] < nums[i]) continue;
                else if(nums[i+1] > nums[i]) {
                    state = 2;
                    q = i;
                }
                else return false;
            }
            else{
                if(nums[i+1] > nums[i]) continue;
                else return false;
            }
        }
        return (state == 2 && q != n-1);
    }
};