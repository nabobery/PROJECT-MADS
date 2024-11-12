// 3097. Shortest Subarray With OR at Least K II

// Solution 1: Sliding Window
// Time complexity: O(n)
// Space complexity: O(32) = O(1)
// The idea is to use a sliding window to find the shortest subarray with OR at least K.
// We can use a vector to store the bits in the array and remove the bits from the left side of the window. 

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);
        int res = INT_MAX;
        for(int i = 0, j = 0; i < n; i++){
            for(int b = 0; b < 32; b++){
                if(nums[i] & (1 << b)) bits[b]++;
            }
            int sum = 0;
            for(int b = 0; b < 32; b++){
                if(bits[b]) sum |= (1 << b);
            }
            while(j <= i && sum >= k){
                res = min(res, i - j + 1);
                for(int b = 0; b < 32; b++){
                    if(nums[j] & (1 << b)) bits[b]--;
                }
                sum = 0;
                for(int b = 0; b < 32; b++){
                    if(bits[b]) sum |= (1 << b);
                }
                j++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};