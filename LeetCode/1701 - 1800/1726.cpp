// 1726. Tuple with Same Product

// Solution 1: Using Hash Map and Counting
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto it : mp) {
            if (it.second >= 2) {
                res += ((it.second)*(it.second -1))*4;
            }
        }
        return res;
    }
};