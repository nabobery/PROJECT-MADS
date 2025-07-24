// 2294. Partition Array Such That Maximum Difference Is K

// Solution 1 using Greedy and Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    // minimum number of partitions such that the maximum difference between the minimum and maximum element in each partition is at most k
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0, mi = nums[0], mx = nums[0];
        for(int i = 1; i < n;i++){
            mi = min(nums[i], mi);
            mx = max(nums[i], mx);
            if(mx - mi > k){
                res++;
                mi = mx = nums[i];
            }
        }
        return res+1;
    }
};