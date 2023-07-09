// 152. Maximum Product Subarray

// O(n) time and space DP solution (Recursive)
class Solution {
public:
    int maxhelper(int i, vector<vector<int>>& dp_max, vector<int>& dp_min, vector<int>& nums, bool take){
        if(i >= nums.size()) return take ? 1 : INT_MIN;
        if(dp_max[take][i] != INT_MIN) return dp_max[take][i];
        if(take) return dp_max[take][i] = max(1, (nums[i] >= 0 ? nums[i]*maxhelper(i+1, dp_max, dp_min, nums, true) : nums[i]*minhelper(i+1,dp_max,dp_min, nums)));
        return dp_max[take][i] = max(maxhelper(i+1, dp_max, dp_min, nums, false),(nums[i] >= 0 ? nums[i]*maxhelper(i+1, dp_max, dp_min, nums, true) : nums[i]*minhelper(i+1,dp_max,dp_min, nums)));
    }

    int minhelper(int i,vector<vector<int>>& dp_max, vector<int>& dp_min, vector<int>& nums){
        if(i >= nums.size()) return 1;
        if(dp_min[i] != INT_MIN) return dp_min[i];
        return dp_min[i] = (nums[i] >= 0 ? nums[i]*minhelper(i+1,dp_max,dp_min, nums) : nums[i]*maxhelper(i+1, dp_max, dp_min, nums, true));
    }

    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp_max(2, vector<int>(nums.size(), INT_MIN));
        vector<int> dp_min(nums.size(), INT_MIN);
        return maxhelper(0, dp_max, dp_min, nums, false);
    }
};

// O(n) time and space DP solution (Iterative)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), result;
        vector<int> dp_min(n), dp_max(n);
        result = nums[0], dp_max[0] = result, dp_min[0] = result;
        for(int i = 1; i < n;i++){
            dp_min[i] = min(nums[i], nums[i] * (nums[i] >= 0 ? dp_min[i-1] : dp_max[i-1]));
            dp_max[i] = max(nums[i], nums[i] * (nums[i] >= 0 ? dp_max[i-1] : dp_min[i-1]));
            result = max(result, dp_max[i]);
        }
        return result;
    }
};


// O(n) time and O(1) space solution 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), curr;
        int curr_max = nums[0], result = nums[0], curr_min = nums[0];
        for(int i = 1; i < n;i++){
            curr = max({nums[i], nums[i]* curr_max, nums[i]*curr_min});
            curr_min = min({nums[i], nums[i]* curr_max, nums[i]*curr_min});
            curr_max = curr;
            result = max(result, curr_max);
        }
        return result;
    }
};

