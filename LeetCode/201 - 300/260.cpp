// 260. Single Number III

// Solution 1: Using Unordered Map
// Time complexity: O(n)
// Space complexity: O(n)
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

// Solution 2: Using Unordered Set
// Time complexity: O(n)
// Space complexity: O(n)
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


// Solution 3: Using Bit Manipulation
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorResult = 0;
        // XOR of all elements
        for (int i = 0; i < n; i++)
            xorResult ^= nums[i];
        int mask = 1;
        // Find the rightmost set bit which is different in both numbers
        while ((mask & xorResult) == 0)
            mask <<= 1;
        // Divide the numbers into two groups based on the rightmost set bit
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] & mask)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        return {num1, num2};
    }
};