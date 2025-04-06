// 2780. Minimum Index of a Valid Split

// Solution 1: Using greedy approach by checking if dominant element is present in both halves and is dominant in both halves.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int,int> mp;
            for(int& num : nums) mp[num]++;
            int dominant = 0, n = nums.size(), l = 0, r;
            for(auto it : mp)
                if(it.second > mp[dominant]) dominant = it.first;
            r = mp[dominant];
            for(int i = 0; i < n;i++){
                if(nums[i] == dominant){
                    l++;
                    r--;
                }
                if(l*2 > i+1 && r*2 > (n-i-1)) return i;
            }
            return -1;
        }
};