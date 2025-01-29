// 2425. Bitwise XOR of All Pairings

// Solution 1: Greedy + Bit Manipulation
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int res = 0;
        if(s1%2 && s2%2){
            for(int& num : nums1) res ^= num;
            for(int& num : nums2) res ^= num;
        }
        else if(s1%2 ^ s2%2){
            if(s1%2) for(int& num : nums2) res ^= num;
            else for(int& num : nums1) res ^= num;
        }
        return res;
    }
};