// 1695. Maximum Erasure Value

// Solution: Sliding Window with Hashing
// Time Complexity: O(n)    
// Space Complexity: O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, l = 0, currSum = 0;
        const int MAX_NUM = 100001;
        bool seen[MAX_NUM] = {false};

        for (int r = 0; r < nums.size(); ++r) {
            while (seen[nums[r]]) {
                seen[nums[l]] = false;
                currSum -= nums[l];
                l++;
            }
            seen[nums[r]] = true;
            currSum += nums[r];
            res = max(res, currSum);
        }

        return res;
    }
};
