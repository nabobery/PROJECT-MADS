// 2411. Smallest Subarrays With Maximum Bitwise OR

// Solution 1: Using Two-Pointer Technique and Bitwise Operations
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool isPossibleToRemove(int reqXor, vector<int>& bitsSet, int num){
        for(int i = 0; i < 32;i++){
            int bit = (1 << i);
            if((bitsSet[i] - bool(bit & num)) < bool(bit & reqXor)) return false;
        }
        return true;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n= nums.size(), prefixXor = 0, r = n-1;
        // if (n == 1) return {1};
        vector<int> bitsSet(32,0), res(n, 0);
        for(int l = n-1; l >= 0;l--){
            prefixXor |= nums[l];
            for(int i = 0; i < 32;i++)
                if(nums[l] & (1 << i)) bitsSet[i]++;
            while(l < r  && isPossibleToRemove(prefixXor, bitsSet, nums[r])){
                for(int i = 0; i < 32;i++)
                    if(nums[r] & (1 << i)) bitsSet[i]--;
                r--;
            }
            res[l] = (r-l+1);
        }
        return res;
    }
};