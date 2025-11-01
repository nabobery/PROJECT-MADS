// 3289. The Two Sneaky Numbers of Digitville

// Solution 1: Easy and Straightforward using visited array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n-2, false);
        vector<int> res;
        for(int i = 0; i < n;i++){
            if(!visited[nums[i]]) visited[nums[i]] = true;
            else res.push_back(nums[i]);
        }
        return res;
    }
};

