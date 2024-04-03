// 713. Subarray Product Less Than K

// Solution 1 using Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, curr = 1, res = 0, n = nums.size();
        while(r < n){
            if(curr*nums[r] < k){
                curr *= nums[r];
                res += (r-l+1);
                r++;
            }
            else{
                curr *= nums[r];
                r++;
                while(l <r && curr >= k){
                    curr /= nums[l];
                    l++;
                }
                res += (r-l);
            }
        }
        return res;
    }   
};

// cleaner Solution 1
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, curr = 1, res = 0, n = nums.size();
        while(r < n){
            curr *= nums[r];
            while(l <= r && curr >= k){
                curr /= nums[l];
                l++;
            }
            res += (r-l+1);
            r++;
        }
        return res;
    }   
};
