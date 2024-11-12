// 3011. Find if Array Can Be Sorted

// Solution 1: Greedy 
// By Going through segments with same bits and checking if the minimum element in the current segment is greater than the maximum element in the previous segment
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size(), prev_mx = 0, curr_mx = nums[0], curr_bits = __builtin_popcount(nums[0]);
        for(int i = 1; i < n;i++){
            int bits = __builtin_popcount(nums[i]);
            if(bits == curr_bits){
                curr_mx = max(nums[i], curr_mx);
                if(nums[i] < prev_mx) return false;
            }
            else{
                prev_mx = curr_mx;
                curr_mx = nums[i];
                if(curr_mx < prev_mx) return false;
                curr_bits = bits;
            }
        }
        return true;
    }
};
