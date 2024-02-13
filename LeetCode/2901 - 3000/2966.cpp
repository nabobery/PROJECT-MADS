// 2966. Divide Array Into Arrays With Max Difference

// Solution 1 Greedy using sorting 
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res(n/3);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n;i += 3){
            if(nums[i+2] - nums[i] <= k)
                res[i/3] = {nums[i], nums[i+1], nums[i+2]};
            else return {};
        }
        return res;
    }
};