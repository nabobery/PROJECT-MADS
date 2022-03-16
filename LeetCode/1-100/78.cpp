// 78. Subsets
// my naive recursive solution using backtracking
class Solution {
public:
    vector<vector<int>> result;
    void helper(int k, vector<int>& nums, vector<int> subset){
        if(k == nums.size()){
            result.push_back(subset);
            return;
        }
        else{
            helper(k+1,nums,subset);
            subset.push_back(nums[k]);
            helper(k+1,nums,subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        helper(0, nums, subset);
        return result;
    }
};

