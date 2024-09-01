// 2134. Minimum Swaps to Group All 1's Together II

// Solution 1: Sliding window
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Count the number of ones in the array
        int n = nums.size(), ones = 0, res = n, zeroes = 0;
        for(int i = 0; i < n;i++) if(nums[i]) ones++;
        // append the array to itself to make it circular
        for(int i=0; i < n;i++) nums.push_back(nums[i]);
        // Sliding window to find the minimum number of swaps to group all ones together
        for(int i = 0; i < ones;i++) if(!nums[i]) zeroes++;
        res = min(res, zeroes);
        // Sliding window
        for(int i = ones;i < 2*n;i++){
            if(!nums[i-ones]) zeroes--;
            if(!nums[i]) zeroes++;
            res = min(zeroes, res);
        }
        return res;
    }
};

// Cleaner version of the above solution
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ones, res = n, zeroes = 0;
        ones = count(nums.begin(), nums.end(), 1);
        for(int i=0; i < n;i++) nums.push_back(nums[i]);
        for(int i = 0; i < ones;i++) if(!nums[i]) zeroes++;
        res = min(res, zeroes);
        for(int i = ones;i < 2*n;i++){
            if(!nums[i-ones]) zeroes--;
            if(!nums[i]) zeroes++;
            res = min(zeroes, res);
        }
        return res;
    }
};

