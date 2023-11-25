// 1887. Reduction Operations to Make the Array Elements Equal

// Solution 1  Greedy Approach
// Time Complexity O(nlogn)
// Space Complexity O(logn)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for(int i = nums.size()-2;i >= 0;i--){
            if(nums[i] != nums[i+1]){
                res += (n-i-1);
            }
        }
        return res;
    }
};

