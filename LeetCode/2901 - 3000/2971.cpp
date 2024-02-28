// 2971. Find Polygon With the Largest Perimeter

// Solution 1 - Sort the array and then check for the largest perimeter (Greedy Approach)
// Time Complexity - O(nlogn)
// Space Complexity - O(logn)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = -1, sum = nums[0] + nums[1];
        for(int i = 2;i < nums.size();i++){
            if(sum > nums[i]) res = max(sum+nums[i], res);
            sum += nums[i];
        }
        return res;
    }
};