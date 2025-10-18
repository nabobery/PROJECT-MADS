// 2598. Smallest Missing Non-negative Integer After Operations

// Solution 1: Math and Straight Simulation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    // target = x += k*val => x % val = target % val
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        // Count occurrences of each remainder when nums[i] is taken modulo value
        vector<int> cnts(value, 0);
        for(int i = 0; i < n;i++){
            int rem = (nums[i] % value + value) % value;
            cnts[rem]++;
        }
        for(int i = 0; i < n;i++){
            int rem = i % value;
            if(!cnts[rem]) return i;
            cnts[rem]--;
        }
        return n;
    }
};