// 2784. Check if Array is Good

// Solution 1: Using Count Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sz = nums.size(), n = sz-1;
        if(n == 0) return false;
        vector<int> cnt(n, 1);
        cnt[n-1] = 2;
        for(int& num: nums){
            if(num > n || cnt[num-1] <= 0) return false;
            cnt[num-1]--;
        }
        return true;
    }
};