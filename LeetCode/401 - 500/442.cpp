// 442. Find All Duplicates in an Array

// Solution 1 Naive and Using extra space
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for(int num : nums){
            if(s.count(num)){
                res.push_back(num);
                s.erase(num);
            }
            else s.insert(num);
        }
        return res;

    }
};

// Solution 2 Naive using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(logn)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) res.push_back(nums[i]);
        }
        return res;
    }
};

// Solution 3 without extra space
// Time complexity: O(n)
// Space complexity: O(1)
// The idea is to use the array itself as a hash table. 
// We do this by negating the value at the index of the number we are currently looking at. 
// If we find that the value at the index of the number we are currently looking at is already negative, then we know that we have seen that number before. 
// We then add it to our result vector.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) res.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return res;
    }
};