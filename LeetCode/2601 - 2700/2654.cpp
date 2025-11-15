// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1

// Solution 1 using Math 
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Observations: 
// If there is at least one 1 in the array, we can make all elements equal to 1 by converting all non-1 elements to 1.
// If there are no 1s, we need to find the shortest subarray with GCD equal to 1. The number of operations required will be the length of that subarray minus 1 plus (n - 1) to convert the rest of the elements to 1.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = n+1, cnt = count(nums.begin(), nums.end(), 1);
        if(cnt != 0) return n - cnt;
        for(int i = 0; i < n;i++){
            int currGCD = nums[i];
            for(int j = i+1; j < n;j++){
                currGCD = gcd(currGCD, nums[j]);
                if(currGCD == 1){
                    ops = min(ops, j-i);
                    break;
                }  
            }
        }
        return ops == n+1 ? -1 : ops+n-1;
    }
};