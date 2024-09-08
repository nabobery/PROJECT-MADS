// 40. Combination Sum II

// Solution 1 using backtracking
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> res;
    void helper(int ind, vector<int>& candidates, int target, int curr, vector<int>& path) {
        if(ind >= candidates.size()){
            if(curr == target) res.push_back(path);
            return;
        }
        if(curr == target){
            res.push_back(path);
            return;
        }
        int n = candidates.size(), prev = -1;
        for(int i = ind; i < n;i++){
            if(curr + candidates[i] > target) break;
            if(prev == candidates[i]) continue;
            path.push_back(candidates[i]);
            helper(i+1,candidates, target, curr + candidates[i], path);
            path.pop_back();
            prev = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(0,candidates, target, 0, path);
        return res;
    }
};

// Cleaner solution
class Solution {
public:
    vector<vector<int>> res;
    void helper(int ind, vector<int>& candidates, int target, vector<int>& path) {
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(ind >= candidates.size() || target < 0) return;
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            helper(i+1, candidates, target - candidates[i], path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(0,candidates, target, path);
        return res;
    }
};

