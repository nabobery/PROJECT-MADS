// 1829. Maximum XOR for Each Query

// Solution 1: Greedy and Prefix XOR 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), mx = pow(2, maximumBit) - 1;
        vector<int> prefixXor(n+1, 0), res(n);
        for(int i = 1; i <= n;i++) prefixXor[i] = nums[i-1] ^ prefixXor[i-1];
        for(int i = 0; i < n;i++) res[i] = prefixXor[n-i] ^ mx;
        return res;
    }
};