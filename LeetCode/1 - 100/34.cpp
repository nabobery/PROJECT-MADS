// 34. Find First and Last Position of Element in Sorted Array

// Solution 1 using Binary Search 2 pass
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                res[1] = mid;
                l = mid+1;
            }
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                res[0] = mid;
                r = mid-1;
            }
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return res;
    }
};
