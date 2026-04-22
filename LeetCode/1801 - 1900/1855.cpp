// 1855. Maximum Distance Between a Pair of Values

// Solution 1: Using Binary Search 
// Time Complexity: O(mlogn)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        for(int j = 0; j < m;j++){
            int end = min(j, n);
            // find the first index i in nums1 such that nums1[i] <= nums2[j]
            auto it = lower_bound(nums1.begin(), nums1.begin() + end, nums2[j], greater<int>());
            if (it != nums1.end()) {
                int i = it - nums1.begin();
                res = max(res, j-i);
            }
        }
        return res;
    }
};

// Solution 2: Using Two Pointers
// Time Complexity: O(m+n)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        int maxDist = 0;

        while (i < n && j < m) {
            // If nums1[i] is less than or equal to nums2[j], we can update the maximum distance and move the pointer j to the right
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            // If nums1[i] is greater than nums2[j], we need to move the pointer i to the right to find a smaller value in nums1
            } else {
                i++;
            }
        }
        return maxDist;
    }
};