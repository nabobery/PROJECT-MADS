// 2040. Kth Smallest Product of Two Sorted Arrays

// Soluton 1: Using Binary Search
// Time Complexity: O(n*logm*logC) where n is the size of nums1 and m is the size of nums2 where C is the range of the product
// Space Complexity: O(1) for the binary search variables

class Solution {
public:
    long long helper(vector<int>& nums2, long long x, long long limit){
        int n2 = nums2.size();
        int l = 0, r  = n2 -1;
        while(l <= r){
            int mid = (l+r)/2;
            if((x >= 0 && nums2[mid]*x <= limit) || (x < 0 && nums2[mid]*x > limit)) l = mid+1;
            else r = mid-1;
        }
        return (x >= 0 ? l : n2 - l);
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        // fix the least product as -1e10 and the greatest product as 1e10
        // since the product of two numbers can be negative or positive
        long long l = -1e10, r = 1e10;
        // binary search for the kth smallest product
        // the product can be negative or positive, so we need to check both sides
        // log C times
        while(l <= r){
            // find the mid product
            // and count how many products are less than or equal to mid
            long long mid = (l+r)/2, count = 0;
            // n times
            for(int i = 0; i < n1;i++){
                // each helper call takes log m time
                count += helper(nums2, nums1[i], mid);
            }
            if(count < k) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};