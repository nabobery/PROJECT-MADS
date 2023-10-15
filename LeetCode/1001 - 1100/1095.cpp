// 1095. Find in Mountain Array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


// Solution 1: Binary Search
// Time Complexity: O(logn)
// Space Complexity: O(1)
// We use binary search 3 times
// First, we find the peak of the mountain array
// Then, we find the target in the left part of the mountain array
// Finally, we find the target in the right part of the mountain array
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the peak in the mountain array
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r)/2;
            // if the mid element is smaller than the next element, then the peak is in the right part
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) l = mid + 1;
            // if the mid element is larger than the next element, then the peak is in the left part
            else r = mid;
        }
        // l is the peak of the mountain array
        int peak = l;
        // reset l and r
        l = 0, r = peak;
        // find the target in the left part of the mountain array
        while (l < r) {
            int mid = (l + r)/2;
            // if the mid element is smaller than the target, then the target is in the right part
            if (mountainArr.get(mid) < target) l = mid + 1;
            // if the mid element is larger than the target, then the target is in the left part
            else r = mid;
        }
        // if the target is found, return the index
        if (mountainArr.get(l) == target) return l;
        // reset l and r
        l = peak, r = n - 1;
        // find the target in the right part of the mountain array
        while (l < r) {
            int mid = (l + r)/2;
            // if the mid element is larger than the target, then the target is in the right part
            if (mountainArr.get(mid) > target) l = mid + 1;
            // if the mid element is smaller than the target, then the target is in the left part
            else r = mid;
        }
        // if the target is found, return the index
        if (mountainArr.get(l) == target) return l;
        // if the target is not found, return -1
        return -1;
    }
};