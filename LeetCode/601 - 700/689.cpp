// 689. Maximum Sum of 3 Non-Overlapping Subarrays

// Solution 1: Using Recursion and Prefix Sum
// Time Complexity: O(n*k)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> res;
    int max_sum;
    void helper(int ind, vector<int>&prefix, int& k, vector<int>& curr, int sum){
        if(ind > prefix.size() - 1) return;
        if(curr.size() == 3){
            if(sum > max_sum){
                res = curr;
                max_sum = sum;
            }
            else if(sum == max_sum && !lexicographical_compare(res.begin(), res.end(), curr.begin(), curr.end())) res = curr;
            return;
        }
        helper(ind+1, prefix, k, curr, sum);
        if(ind+k < prefix.size()){
            curr.push_back(ind);
            helper(ind+k, prefix, k, curr, sum + prefix[ind+k] - prefix[ind]);
            curr.pop_back();
        }

    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        res.resize(3, 1e5);
        vector<int> prefix(n+1, 0), curr;
        max_sum = 0;
        for(int i = 0; i < n;i++) prefix[i+1] = nums[i] + prefix[i];
        helper(0, prefix, k, curr, 0);
        return res;
    }
};

// Solution 2: Using DP
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0), left(n, 0), right(n, 0), res(3, 0);
        // prefix[i] = sum of first i elements
        for(int i = 0; i < n;i++) prefix[i+1] = nums[i] + prefix[i];
        // left[i] = starting index of subarray of length k with maximum sum left of i 
        // initialising sum to sum of first k elements
        int sum = prefix[k] - prefix[0];
        for(int i = k; i < n;i++){
            if(prefix[i+1] - prefix[i+1-k] > sum){
                left[i] = i+1-k;
                sum = prefix[i+1] - prefix[i+1-k];
            }
            else left[i] = left[i-1];
        }
        // right[i] = starting index of subarray of length k with maximum sum right of i
        // initialising sum to sum of last k elements
        sum = prefix[n] - prefix[n-k];
        right[n-k] = n-k;
        for(int i = n-k-1; i >= 0;i--){
            if(prefix[i+k] - prefix[i] >= sum){
                right[i] = i;
                sum = prefix[i+k] - prefix[i];
            }
            else right[i] = right[i+1];
        }
        // finding the maximum sum of 3 non-overlapping subarrays
        int max_sum = 0;
        // i is the starting index of middle subarray
        for(int i = k; i <= n-2*k;i++){
            int l = left[i-1], r = right[i+k];
            int sum = prefix[i+k] - prefix[i] + prefix[l+k] - prefix[l] + prefix[r+k] - prefix[r];
            if(sum > max_sum){
                max_sum = sum;
                res = {l, i, r};
            }
        }
        return res;
    }
};