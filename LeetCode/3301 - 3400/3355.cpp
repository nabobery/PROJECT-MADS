// 3355. Zero Array Transformation I

// Solution 1 using Prefix Sum
// Time Complexity: O(n + q)
// Space Complexity: O(n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(auto& query: queries){
            prefix[query[0]]++;
            prefix[query[1]+1]--;
        }
        int decrement = 0;
        for(int i = 0; i < n;i++){
            decrement += prefix[i];
            if(decrement < nums[i]) return false;
        }
        return true;
    }
};