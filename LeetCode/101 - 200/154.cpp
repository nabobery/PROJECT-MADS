// 154. Find Minimum in Rotated Sorted Array II

// Solution 1: Binary Search
// Time Complexity: O(log n) in the average case, O(n) in the worst case
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid;
        while(l < r){
            mid = (l+r)/2;
            // If the middle element is greater than the rightmost element, the minimum is in the right half
            if(nums[mid] > nums[r])
                l = mid+1;
            // If the middle element is less than the rightmost element, the minimum is in the left half
            else if(nums[mid] < nums[r]) r = mid;
            // If the middle element is equal to the rightmost element, we cannot determine the side, so we reduce the search space by moving the right pointer one step to the left
            else r--;
        }
        // At the end of the loop, l will be pointing to the minimum element
        return nums[l];
    }
};