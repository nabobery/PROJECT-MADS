/*15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []
*/
// using sort and unordered_map
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        if(nums[0] > 0){
            return {};
        }
        vector<vector<int>> result;
        unordered_map <int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n - 2; i++){
            if(nums[i] > 0)
                break;
            for(int j = i+1;j < n - 1;j++){
                int temp = -(nums[i] + nums[j]);
                if(mp.find(temp) != mp.end() && mp[temp] > j){
                    result.push_back({nums[i], nums[j],temp});
                }
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }
        return result;
    }
};

// using 2 pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        if(nums[0] > 0){
            return {};
        }
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1, r = n-1;
            while(l < r){
                int temp = nums[l] + nums[r] + nums[i];
                if(temp > 0) r--;
                else if(temp < 0) l++;
                else{
                    result.push_back({nums[i],nums[l],nums[r]});
                    while (l < r && nums[l]==nums[l+1]) l++;
                    while (r > 0 && nums[r]==nums[r-1]) r--;
                    l++; r--;
                }
            }
        }
        return result;
    }
};