// 413. Arithmetic Slices
// naive solution using 2 for loops (Bruteforce) O(N^2) time solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int result = 0;
        // iterate over the array and check for the arithmetic sequence
        for(int i = 1; i < n-1;i++){
            // check if the current element is a part of an arithmetic sequence
            int prev = nums[i] - nums[i-1];
            int curr = nums[i+1] - nums[i];
            // if it is then check for the next elements
            if(prev == curr){
                result++;
                // check for the next elements
                for(int j = i +2; j < n;j++){
                    if(nums[j] - nums[j-1] == nums[j-1] - nums[j-2]){
                        result++;
                    }
                    else break;
                }
            }
        }
        return result;
    }
};

// dp solution O(n) time and O(n) space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<int> dp(n,0);
        // check for the first 3 elements
        if(nums[2] - nums[1] == nums[1] - nums[0]) dp[2] = 1;
        // base case
        int result = dp[2];
        // iterate over the array and check for the arithmetic sequence
        for(int i = 3; i < n;i++){
            // check if the current element is a part of an arithmetic sequence
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] = dp[i-1] + 1;
            result += dp[i];
        }
        return result;
    }
};

// DP Solution O(n) time and O(1) space using ending technique
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int result = 0, curr = 0;
        // iterate over the array and check for the arithmetic sequence
        for(int i = 2; i < n;i++){
            // check if the current element is a part of an arithmetic sequence
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                curr++;
                // result = curr*curr+1/2 so we add from 1 to curr
                result += curr;
            }
            // if it is not then reset the curr
            else curr = 0;
        }
        return result;
    }
};

// using sliding window kinda method
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int result = 0;
        for(int i = 2, j = 1; i < n;i++){
            if(nums[i] - nums[i-1] != nums[j] - nums[j-1])
                j = i;
            result += i - j;
        }
        return result;
    }
};
