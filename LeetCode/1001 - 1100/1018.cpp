// 1018. Binary Prefix Divisible By 5

// Solution 1 : Using Simulation (using Modulo Property)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), curr = 0;
        vector<bool> res(n);
        for(int i = 0; i < n;i++){
            curr *= 2;
            curr += (nums[i] == 1);
            res[i] = (curr% 5 == 0);
            curr %= 5;
        }
        return res;
    }
};