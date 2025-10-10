// 11. Container With Most Water

// Solution 1: Greedy Two-Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, n = height.size(), l = 0, r = n-1;
        while(l < r){
            res = max(min(height[l], height[r]) * (r-l), res);
            if(height[l] > height[r]) r--;
            else l++;
        }
        return res;
    }
};