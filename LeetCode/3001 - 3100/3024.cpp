// 3024. Type of Triangle

// Solution 1: Staightforward
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Check if the three sides can form a triangle using the triangle inequality theorem
        // If any two sides are less than or equal to the third side, return "none"
        if(nums[0] + nums[1] <= nums[2] || nums[1] + nums[2] <= nums[0] || nums[0] + nums[2] <= nums[1]) return "none";
        // Check the type of triangle based on the lengths of the sides
        unordered_set<int> s(nums.begin(), nums.end());
        if(s.size() == 1) return "equilateral";
        else if(s.size() == 2) return "isosceles";
        return "scalene";
    }
};