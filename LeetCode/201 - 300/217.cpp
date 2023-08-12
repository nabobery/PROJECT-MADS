// 217. Contains Duplicate

// Solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size();i++){
            if(!s.count(nums[i])) s.insert(nums[i]);
            else return true;
        }
        return false;
    }
};

// Solution 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size();i++){
            if(nums[i] != nums[i-1]) continue;
            else return true;
        }
        return false;
    }
};