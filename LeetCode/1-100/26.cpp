// 26. Remove Duplicates from Sorted Array
// Two pointer Approach
// using one pointer that keeps track of original elements and another that keeps track of unique element
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 1; i < n;i++){
            // skip duplicate
            if(nums[i] ==  nums[i-1]){
                j++;
            }
            // keep unique
            else{
                nums[i-j] = nums[i];
            }
        }
        // return size - number of duplicate which is number of unique elements
        return (n-j);
    }
};

