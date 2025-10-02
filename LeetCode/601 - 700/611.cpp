// 611. Valid Triangle Number

// Solution 1: Using Sorting and Two Pointers
// the idea is to find triplets such that nums[i] + nums[j] > nums[k]
// now, we have to do this efficiently, so we sort the array first
// then, we fix the largest element of the triplet, and use two pointers to find the valid pairs
// all the elements between this element and j can form a valid triplet with nums[j] 

// Time Complexity: O(nlogn + n^2) = O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n;k++){
            if(nums[k] == 0) continue;
            int l = 0, r = k-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[k]){
                    res += (r-l);
                    r--;
                }
                else l++;
            }
        }
        return res;
    }
};