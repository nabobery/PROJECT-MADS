// 78. Subsets

// Solution 1: Naive Recursion + Backtracking
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
public:
    int n;
    vector<vector<int>> res;
    void helper(int i, vector<int>& curr, vector<int>& nums){
        if(i >= n){
            res.push_back(curr);
            return;
        }
        helper(i+1, curr, nums);
        curr.push_back(nums[i]);
        helper(i+1, curr, nums);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        helper(0, temp, nums);
        return res;
    }
};

// Solution 2: Bit Manipulation (Efficient Memory Usage)
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < (1 << n); i++){
            vector<int> temp;
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                    temp.push_back(nums[j]);
            res.push_back(temp);
        }
        return res;
    }
};

