// 2441. Largest Positive Integer That Exists With Its Negative

// Solution 1 using Hashset
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = -1;
        for(int& num : nums)
            if(num > 0 && s.count(-num))
                res = max(res, num);
        return res;
    }
};

// Solution 2 using Sorting and Two Pointers
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int i = 0, j = nums.size() - 1; i < j;)
            if(nums[i] == -nums[j])
                res = max(res, nums[j--]);
            else if(nums[i] > -nums[j])
                j--;
            else
                i++;
        return res;
    }
};