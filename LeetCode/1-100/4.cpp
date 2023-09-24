// 4. Median of Two Sorted Arrays

// Solution1: Naive sorting solution
// Time Complexity: O((m+n)log(m+n))
// Space Complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(auto i : nums1) nums.push_back(i);
        for(auto i : nums2) nums.push_back(i);
        sort(nums.begin(), nums.end());
        return (nums.size()%2 ? nums[nums.size()/2] : (double)(nums[nums.size()/2-1] + nums[nums.size()/2])/2);
    }
};

// Solution2: Merge sort solution
// Time Complexity: O(m+n)
// Space Complexity: O(1)
class Solution {
public:
    int p1 = 0, p2 = 0;
    // the basic idea is to traverse the two arrays and return the element in sorted order
    int getMin(vector<int>& nums1, vector<int>& nums2){
        //if both arrays have elements
        if(p1 < nums1.size() && p2 < nums2.size()){
            // if nums1[p1] < nums2[p2], return nums1[p1] and p1++
            if(nums1[p1] < nums2[p2]) return nums1[p1++];
            // else return nums2[p2] and p2++
            else return nums2[p2++];
        }
        // if nums1 has elements, return nums1[p1] and p1++
        else if(p1 < nums1.size()) return nums1[p1++];
        // else return nums2[p2] and p2++
        else return nums2[p2++];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // if the total number of elements is odd, return the middle element
        if((m+n)%2){
            // traverse (m+n)/2 times and return the m+n/2th element
            for(int i = 0; i < (m+n)/2; i++) getMin(nums1, nums2);
            return (double)getMin(nums1, nums2);       
        }
        else{
            // traverse (m+n)/2-1 times and return the average of m+n/2-1th and m+n/2th element
            for(int i = 0; i < (m+n)/2-1; i++) getMin(nums1, nums2);
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2))/2;
        }
    }
};

// Solution3: Binary search solution intuitive one
// Time Complexity: O(log(min(m,n)))
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure nums1 is the smaller one
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        // m is the size of nums1, n is the size of nums2
        int m = nums1.size(), n = nums2.size(), s = m+n;
        // l is the left bound of the binary search, r is the right bound of the binary search
        int l = 0, r = m;
        // binary search
        while(1){
            // i is the number of elements in nums1 that are smaller than the median
            int i = (l+r)/2;
            // j is the number of elements in nums2 that are smaller than the median
            int j = (s+1)/2-i;
            // left_1 is the left element of the median in nums1
            int left_1 = (i > 0) ? nums1[i-1] : INT_MIN;
            // right_1 is the right element of the median in nums1
            int right_1 = (i < m) ? nums1[i] : INT_MAX;
            // left_2 is the left element of the median in nums2
            int left_2 = (j > 0) ? nums2[j-1] : INT_MIN;
            // right_2 is the right element of the median in nums2
            int right_2 = (j < n) ? nums2[j] : INT_MAX;
            // if we got the paritions right, return the median
            if(left_1 <= right_2 && left_2 <= right_1){
                // if the total number of elements is odd, return the median
                if(s%2) return max(left_1, left_2);
                // else return the average of the two medians
                else
                    return (max(left_1, left_2) + min(right_1, right_2))/2.0;
            }
            // if the left element of the median in nums1 is greater than the right element of the median in nums2
            // there are too many elements in the left side of the median, wo we need to move r to left
            else if(left_1 > right_2) r = i-1;
            // else move l to right
            else l = i+1;
        }
        return 0;
    }
};
