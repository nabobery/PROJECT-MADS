// 3507. Minimum Pair Removal to Sort Array I

// Solution 1: Simulation
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    bool isNonDecreasing(vector<int>& nums){
        int n = nums.size();
        for(int i = 1; i < n;i++) if(nums[i-1] > nums[i]) return false;
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0, n;
        while(!isNonDecreasing(nums)){
            int mi = INT_MAX, ind = 0;
            n = nums.size();
            for(int i = 1; i < n;i++){
                if((nums[i] + nums[i-1]) < mi){
                    mi = nums[i] + nums[i-1];
                    ind = i-1;
                }
            }
            nums[ind] = mi;
            for(int i =ind+1; i < n-1;i++) nums[i] = nums[i+1];
            nums.pop_back();
            res++;
        }
        return res;
    }
};