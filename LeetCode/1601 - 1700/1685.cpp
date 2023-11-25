// 1685. Sum of Absolute Differences in a Sorted Array

// Solution 1 using Prefix Sum
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1 , 0), res(n);
        for(int i = 0; i < n;i++) prefix[i+1] = prefix[i] + nums[i];
        for(int i = 0; i < n;i++){
            if(i > 0 && i < n-1){
                res[i] = nums[i]*i - prefix[i] + prefix[n] - prefix[i+1] - nums[i]*(n-i-1);
            }
            else{
                if(i == 0){
                    res[i] = prefix[n] - nums[i]*n;
                }
                else{
                    res[i] = nums[i]*n - prefix[n];
                }
            }
        }
        return res;
    }
};

// Solution 2 without using Memory using Prefix Sum
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int total = accumulate(nums.begin(), nums.end(), 0);
        int prefix = 0;
        for(int i = 0; i < n;i++){
            res[i] = nums[i]*i - prefix + total - prefix - nums[i]*(n-i);
            prefix += nums[i];
        }
        return res;
    }
};