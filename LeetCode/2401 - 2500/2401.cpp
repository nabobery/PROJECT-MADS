// 2401. Longest Nice Subarray

// Solution 1: using Bitsets and Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        bool check(bitset<32>& a, bitset<32>& b) {
            return (a & b).any();  
        }
        void set(bitset<32>& a, bitset<32>& b) {
            a |= b;
        }
        void unset(bitset<32>& a, bitset<32>& b) {
            a &= ~b;
        }
        int longestNiceSubarray(vector<int>& nums) {
            int res = 1, l = 0;
            bitset<32> window;
            for(int r = 0; r < nums.size();r++){
                bitset<32> curr(nums[r]);
                while(check(window, curr)){
                    bitset<32> left(nums[l]);
                    unset(window, left);
                    l++;
                }
                set(window, curr);
                res = max(res, r-l+1);
            }
            return res;
        }
};