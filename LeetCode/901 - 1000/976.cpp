// 976. Largest Perimeter Triangle

// Solution 1: Greedy Approach using Sorting
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if sorting in place, otherwise O(n)
// the idea is to fix c as the largest side and check if a + b > c
// as we want the largest perimeter, we choose the largest a and b possible for each c
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for(int i = 2; i < n;i++){
            if(nums[i-1] + nums[i-2] > nums[i]) res = max(res, nums[i] + nums[i-1] + nums[i-2]);
        }
        return res;
    }
};

// starting from the largest side, we can return the first valid triangle we find
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            if(nums[i+1] + nums[i+2] > nums[i]) return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};