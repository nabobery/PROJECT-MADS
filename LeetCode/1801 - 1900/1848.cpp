// 1848. Minimum Distance to the Target Element

// Solution 1: Straightforward Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums[start] == target) return 0;
        int n = nums.size(), res = n;
        for(int i = 0; i < n;i++){
            if(nums[i] == target) res = min(res, abs(i-start));
        }
        return res;
    }
};

// Solution 2: Using Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int> indices;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) indices.push_back(i);
        }
        if(indices.empty()) return -1; // No target found
        auto it = lower_bound(indices.begin(), indices.end(), start);
        int res = INT_MAX;
        if(it != indices.end()) res = min(res, abs(*it - start));
        if(it != indices.begin()) res = min(res, abs(*(it - 1) - start));
        return res;
    }
};