// 2799. Count Complete Subarrays in an Array

// Solution 1: Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int> mp;
            unordered_set<int> s(nums.begin(), nums.end());
            int l = 0, n= nums.size(), dis = s.size(), res = 0;
            for(int r = 0; r < n;r++){
                mp[nums[r]]++;
                while(mp.size() == dis){
                    res += (n-r);
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }
            }
            return res;
        }
};