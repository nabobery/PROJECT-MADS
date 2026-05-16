// 153. Find Minimum in Rotated Sorted Array

// Solution 1: Binary Search
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid;
        while(l < r){
            mid = (l+r)/2;
            // If the middle element is greater than the rightmost element, then the minimum is in the right half
            // because the array is rotated sorted, so the left half is sorted and the minimum cannot be in it
            if(nums[mid] > nums[r])
                l = mid+1;
            // If the middle element is less than the rightmost element, then the minimum is in the left half
            else r = mid;
        }
        // At the end of the loop, l == r, which means we have found the minimum element
        return nums[l];
    }
};