// 3151. Special Array I

// Solution 1: Straightforward
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool prev = nums[0]%2;
        for(int i = 1; i < nums.size();i++){
            if(prev == nums[i]%2) return false;
            prev = nums[i]%2;
        }
        return true;
    }
};