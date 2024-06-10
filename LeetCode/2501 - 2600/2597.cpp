// 2597. The Number of Beautiful Subsets

// Solution 1 Recursion + Backtracking (TLE)
// Time complexity: O(2^n*n)
// Space complexity: O(n)
class Solution {
public:
    int res;
    bool isBeautiful(vector<int>& vec, int k){
        if(vec.empty()) return false;
        unordered_set<int> s(vec.begin(), vec.end());
        for(int i : vec)
            if(s.count(i-k) || s.count(i+k)) return false;
        return true;
    }
    void helper(int ind, vector<int>& nums, vector<int>& curr, int k){
        if(ind >= nums.size()){
            if(isBeautiful(curr, k)) res++;
            return;
        }
        curr.push_back(nums[ind]);
        helper(ind+1, nums, curr, k);
        curr.pop_back();
        helper(ind+1, nums, curr, k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        res = 0;
        vector<int> curr;
        helper(0, nums, curr, k);
        return res;
    }
};


// Solution 2 using bitset
// Time complexity: O(2^n*n)
// Space complexity: O(n)

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return helper(nums, k, 0, 0);
    }
    int helper(vector<int>& nums, int k, int ind, int mask){
        if(ind == nums.size()) return mask > 0 ? 1 : 0;
        bool flag = true;
        for(int i = 0; i < ind; i++){
            if((mask & (1 << i)) && abs(nums[i] - nums[ind]) == k){
                flag = false;
                break;
            }
        }
        int dontInclude = helper(nums, k, ind+1, mask);
        int include;
        if(flag) include = helper(nums, k, ind+1, mask | (1 << ind));
        else include = 0;
        return dontInclude + include;
    }
};

// Solution 3 using Recursion + Backtracking + Sorting
// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    int res;
    void helper(int ind, vector<int>& nums, vector<int>& cnt, int k){
        // if we have reached the end of the array then increment the result
        if(ind >= nums.size()){
            res++;
            return;
        }
        // if there exists a number which is k less than the current number and its frequency is greater than 0 then we can't include the current number in the subset and move on to next number
        if(nums[ind]-k > 0 && cnt[nums[ind] - k] > 0) helper(ind+1, nums,cnt, k);
        // else we can choose to include/not include it in the subset
        else{
            helper(ind+1, nums,cnt, k);
            cnt[nums[ind]]++;
            helper(ind+1, nums,cnt, k);
            cnt[nums[ind]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        // to take care of empty subset
        res = -1;
        // sorting the array
        sort(nums.begin(), nums.end());
        // counting the frequency of each element
        vector<int> cnt(nums.back()+1, 0);
        // calling the helper function
        helper(0, nums,cnt, k);
        return res;
    }
};

// More Solutions to be added soon
