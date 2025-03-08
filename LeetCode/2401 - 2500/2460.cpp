// 2460. Apply Operations to an Array


// Solution 1: Simple 2 Pass solution
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size(), p = 0;
            vector<int> res(nums.begin(), nums.end());
            for(int i = 0; i < n-1;i++){
                if(res[i] == res[i+1]){
                    res[i] *= 2;
                    res[i+1] = 0;
                }
            }
            for(int i = 0; i < n;i++)
                if(res[i] != 0) res[p++] = res[i];
            for(int i = p; i < n;i++) res[i] = 0;
            return res;
        }
};
