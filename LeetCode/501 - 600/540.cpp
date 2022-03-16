// 540. Single Element in a Sorted Array
#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1,mid;
        if(n == 1){
            return nums[0];
        }
        if(nums[low] != nums[low + 1])
            return nums[low];
        if(nums[high] != nums[high -1])
            return nums[high];
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] != nums[mid -1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if((nums[mid] == nums[mid + 1] && mid % 2 == 0) || (nums[mid] == nums[mid -1] && mid % 2 != 0)){
                low = mid + 1;
            }
            else
                high = mid -1; 
        }
        return -1;
    }
    
};