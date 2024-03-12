// 977. Squares of a Sorted Array

// Solution 1 Naive and simple
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int& num : nums) num *= num;
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Solution 2 Two pointers
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(abs(nums[l]) > abs(nums[r])) {
                res[i] = nums[l] * nums[l];
                l++;
            } else {
                res[i] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
};