// 491. Non-decreasing Subsequences

// brute force with bracktracking O(n^2* 2^n) solution
class Solution {
public:
    set<vector<int>> result;
    void helper(int index, vector<int>& nums, vector<int>& sequence){
        if (index == nums.size()) {
            if (sequence.size() >= 2) {
                result.insert(sequence);
            }
            return;
        }
        if (sequence.empty() || sequence.back() <= nums[index]) {
            sequence.push_back(nums[index]);
            helper(index + 1,nums,sequence);
            sequence.pop_back();
        }
        helper(index + 1,nums,sequence);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sequence;
        helper(0,nums,sequence);
        return vector(result.begin(),result.end());
    }
};