// 416. Partition Equal Subset Sum
/* We need to see if sum is odd or even first. if it's odd then equal subset not possible. 
if even, we need to see if there exists a susbet with sum equal to sum/2(as it proves there' anohter subset of sum/2)
*/
// memory efficient dp solution
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return false;
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){ // if sum can't divide into 2 subsets return false
            return false;
        }
        int reqsum = sum/2;
        bool dp[reqsum + 1]; // an array to store boolean values
        for(int i = 0; i < reqsum + 1; i++){
            dp[i] = false;
        }
        for(int i = 0; i < n;i++){
            for(int j = reqsum; j >= nums[i]; j--){ // the number should be less than or eaual to subset Sum
                // to check if sum - nums[i] can be formed 
                if(dp[j - nums[i]] == true || j == nums[i]){
                     dp[j] = true;
                }
            }
        }
        return dp[reqsum];
    }
};

// average Solution
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int reqsum = sum/2;
        bool dp[reqsum + 1][n+1];
        for(int i = 0; i <= n; i++){
            dp[0][i] = true;
        }
        for(int i = 1; i <= reqsum; i++){
            dp[i][0] = false;
        }
        for(int i = 1; i <= reqsum;i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j-1];
                if(i >= nums[j - 1]){
                     dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
                }
            }
        }
        return dp[reqsum][n];
    }
};
