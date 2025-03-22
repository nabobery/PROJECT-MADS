// 2206. Divide Array Into Equal Pairs

// Solution 1: using Hash Map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int,int> mp;
            for(int num: nums) mp[num]++;
            for(auto it: mp) if(it.second%2) return false;
            return true;
        }
};

// Solution 2: using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            for(int i=0; i<nums.size(); i+=2) if(nums[i]!=nums[i+1]) return false;
            return true;
        }
};