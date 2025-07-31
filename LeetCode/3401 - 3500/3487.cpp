// 3487. Maximum Unique Subarray Sum After Deletion

// Solution 1: Using Set to Track Unique Elements
// This solution finds the maximum sum of unique elements in the array by picking the largest unique elements.
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(*s.rbegin() < 0) return *s.rbegin();
        int res = 0;
        for(auto it = s.rbegin(); it != s.rend();it++){
            if(*it < 0) break;
            res += *it;
        }
        return res;
    }
};