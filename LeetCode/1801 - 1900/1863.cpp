// 1863. Sum of All Subset XOR Totals

// Solution 1 using Recursion and Bit Manipulation
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    unordered_set<int> visited;
    int res, n;
    void helper(int i, int currMask, vector<int>& nums){
        if(i >= n) return;
        int t = 0;
        if(i >= 0){
            for(int j = 0; j < n;j++)
                if(currMask & (1 << j)) t ^= nums[j];
            if(!visited.count(currMask)) res += t;
            visited.insert(currMask);
        }
        helper(i+1, currMask, nums);
        helper(i+1, currMask ^ (1 << (i+1)), nums);
    }
    int subsetXORSum(vector<int>& nums) {
        res = 0; n= nums.size();
        helper(-1, 0, nums);
        return res;
    }
};

// Solution 2 using Recursion and Backtracking
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    int res;
    void helper(int i, int curr, vector<int>& nums){
        if(i >= nums.size()) return;
        res += curr;
        for(int j = i+1; j < nums.size(); j++)
            helper(j, curr ^ nums[j], nums);
    }
    int subsetXORSum(vector<int>& nums) {
        res = 0;
        for(int i = 0; i < nums.size(); i++)
            helper(i, nums[i], nums);
        return res;
    }
};
