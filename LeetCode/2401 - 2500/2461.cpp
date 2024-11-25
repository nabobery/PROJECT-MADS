// 2461. Maximum Sum of Distinct Subarrays With Length K

// Solution 1: Using Sliding Window
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, curr = 0;
        unordered_set<int> s;
        int l = 0, n = nums.size();
        for(int r = 0; r < n;r++){
            if(s.count(nums[r])){
                if(s.size() == k) res = max(res, curr);
                while(s.count(nums[r])){
                    s.erase(nums[l]);
                    curr -= nums[l++];
                }
            }
            else{
                if(s.size() >= k){
                    res = max(res, curr);
                    s.erase(nums[l]);
                    curr -= nums[l++];
                } 
            }
            curr += nums[r];
            s.insert(nums[r]);
        }
        if(s.size() == k) res = max(curr, res);
        return res;
    }
};

// Cleaner and more concise solution
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, curr = 0;
        unordered_set<int> s;
        int l = 0, n = nums.size();
        for(int r = 0; r < n;r++){
            if(s.count(nums[r])){
                if(s.size() == k) res = max(res, curr);
                while(s.count(nums[r])) curr -= nums[l], s.erase(nums[l++]);
            }
            else{
                if(s.size() >= k) res = max(res, curr), curr -= nums[l], s.erase(nums[l++]);
            }
            curr += nums[r];
            s.insert(nums[r]);
        }
        return s.size() == k ? max(curr, res) : res;
    }
};