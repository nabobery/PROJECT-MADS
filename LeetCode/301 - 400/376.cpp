// 376. Wiggle Subsequence

// O(n^2) time O(n) space DP solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // if size of array is 1 return 1
        if(n == 1) return 1;
        // up[i] is the length of longest wiggle subsequence ending at index i with positive difference
        // down[i] is the length of longest wiggle subsequence ending at index i with negative difference
        vector<int> up(n,0), down(n,0);
        for(int i = 1; i < n;i++){
            for(int j = 0; j < i;j++){
                // if nums[i] > nums[j] then we can add nums[i] to the end of subsequence ending at j with negative difference
                if(nums[i] > nums[j]){
                    up[i] = max(up[i], down[j] + 1);
                }
                // if nums[i] < nums[j] then we can add nums[i] to the end of subsequence ending at j with positive difference
                else if (nums[i] < nums[j]){
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        // return the max of up[n-1] and down[n-1] + 1
        return 1 + max(up[n-1], down[n-1]);
    }
};

// O(n) time O(n) space DP solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        // up[i] is the length of longest wiggle subsequence ending at index i with positive difference
        // down[i] is the length of longest wiggle subsequence ending at index i with negative difference
        vector<int> up(n,0), down(n,0);
        for(int i = 1; i < n;i++){
            // if nums[i] > nums[i-1] then we can add nums[i] to the end of subsequence ending at i-1 with negative difference
            if(nums[i] > nums[i-1]){
                // up[i] = down[i-1] + 1
                // down[i] = down[i-1]
                up[i] = down[i-1] +1;
                down[i] = down[i-1];
            }
            // if nums[i] < nums[i-1] then we can add nums[i] to the end of subsequence ending at i-1 with positive difference
            else if(nums[i] < nums[i-1]){
                // up[i] = up[i-1]
                // down[i] = up[i-1] + 1
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            // if nums[i] == nums[i-1] then we can't add nums[i] to the end of subsequence ending at i-1 so no wiggle
            else{
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        // return the max of up[n-1] and down[n-1] + 1
        return 1 + max(up[n-1], down[n-1]);
    }
};

// O(n) time O(1) space DP solution (space optimizing the previous solution)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int up = 0, down = 0;
        for(int i = 1; i < n;i++){
            if(nums[i] > nums[i-1]) up = down + 1;
            else if(nums[i] < nums[i-1]) down = up + 1;
        }
        return 1 + max(up, down);
    }
};

// O(n) time O(1) space greedy solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // if size of array is 1 return 1
        int n = nums.size();
        if(n == 1) return 1;
        // prev is intialised the difference between nums[1] and nums[0]
        // result is intialised to 2(which means there is a wiggle) if prev difference is not 0 else 1
        int prev = nums[1] - nums[0], result = prev != 0 ? 2 : 1;
        for(int i = 2; i < n;i++){
            // curr is the difference between nums[i] and nums[i-1]
            int curr = nums[i] - nums[i-1];
            // if prev and curr have opposite signs then we have a wiggle
            if((curr > 0 && prev <= 0) || (curr < 0 && prev >= 0)){
                prev = curr;
                result++;
            }
        }
        // return the result
        return result;
    }
};
