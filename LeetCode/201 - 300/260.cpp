/*260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer
Example 2:
Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]

Solution1: 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for (auto x : mp){
            if(x.second == 1){
                result.push_back(x.first);
            }
        }
        return result;
    }
};

Solution2: 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> intSet;
        vector<int> result;
        for (int i = 0; i < n; i++){
            if (intSet.find(nums[i]) == intSet.end())
                intSet.insert(nums[i]);
            else
                intSet.erase(nums[i]);
        }
        for (auto itr = intSet.begin(); itr != intSet.end(); itr++)
            result.push_back(*itr);
        return result;
    }
};
*/