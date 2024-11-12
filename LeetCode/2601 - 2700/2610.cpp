// 2610. Convert an Array Into a 2D Array With Conditions

// Solution 1 : Naive using hash table
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = 0;
        for(int num : nums){
            mp[num]++;
            n = max(n, mp[num]);
        }
        vector<vector<int>> res(n);
        for(auto it : mp){
            for(int i = 0; i < it.second;i++) res[i].push_back(it.first);
        }
        return res;
    }
};

