// 80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return nums.size();
        int j  = 2;
        for(int i = 2; i < n;i++){
            // using this we make sure that they're atmost 2 duplicates in nums
            if(nums[i] != nums[j - 2]){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

// in general (for any k)
int removekDuplicates(vector<int>& nums, int k) {
    int i = 0;
    for (int n : nums)
        if (i < k || n > nums[i-k])
            nums[i++] = n;
    return i;
}

