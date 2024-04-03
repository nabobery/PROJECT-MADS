// 2444. Count Subarrays With Fixed Bounds

// Solution 1 using Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
// The idea is to keep track of the last occurrence of the minimum and maximum values in the window  such that all elements in the window are in the range [minK, maxK].
// We keep track of the start of the window and the last occurrence of the minimum and maximum values in the window.
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int start = 0, minl = -1, maxl = -1, n = nums.size();
        for(int i = 0; i < n;i++){
            // If the current element is in the range [minK, maxK] update the last occurrence of the minimum and maximum values in the window
            if(nums[i] >= minK && nums[i] <= maxK){
                if(nums[i] == minK) minl = i;
                if(nums[i] == maxK) maxl = i;
            } 
            // If the current element is not in the range [minK, maxK] reset the last occurrence of the minimum and maximum values in the window
            // and update the start of the window
            else{
                minl = -1; maxl = -1;
                start = i+1;
            }
            // If the window is valid, add the number of subarrays that can be formed with the current window
            // The number of subarrays that can be formed with the current window is the number of choices for the start of the window
            // which can be in the range [start, min(minl, maxl)].
            res += max(0, min(minl, maxl) - start + 1);
        }
        return res;
    }
};
