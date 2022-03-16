// 39. Combination Sum
// naive solution using backtracking
class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& candidates, vector<int> currSet, int curr, int i, int target){
        if(i == candidates.size())
            return;
        int prev = curr;
        int val = candidates[i];
        while(curr < target){
            curr += val;
            currSet.push_back(val);
        }
        if(curr == target){
            result.push_back(currSet);
        }
        while(curr > prev){
            curr -= val;
            currSet.pop_back();
            if(curr >= 0){
                helper(candidates,currSet,curr,i+1,target);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates,temp,0,0,target);
        return result;
    }
};

// another efficient backtracking solution
class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& candidates, vector<int>& currSet, int i, int target){
        if(!target){
            result.push_back(currSet);
            return;
        }
        // skip elements > target as it's sorted no problem
        for (int j = i; j != candidates.size() && target >= candidates[j]; ++j) {
            currSet.push_back(candidates[j]);
            helper(candidates,currSet,j,target - candidates[j]);
            currSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates,temp,0,target);
        return result;
    }
};

