// 1508. Range Sum of Sorted Subarray Sums

// Solution 1 using sliding window, prefix sum and sorting
// Time complexity: O(n^2logn^2)
// Space complexity: O(n^2)
class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int pre = 0, temp = 0;
        vector<int> sub;
        for(int i = 0; i < n;i++){
            pre = nums[i];
            temp = pre;
            sub.push_back(temp);
            for(int j = i+1; j < n;j++){
                temp += nums[j];
                sub.push_back(temp);
            }
        }
        sub.push_back(0);
        sort(sub.begin(), sub.end());
        for(int i = 1; i < sub.size();i++) sub[i] = ((long)sub[i]+sub[i-1])%mod;
        return (sub[right]-sub[left-1])%mod;
    }
};

// Solution 2 using sliding window and sorting
// Time complexity: O(n^2logn)
// Space complexity: O(n^2)
class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        for(int i = 0; i < n;i++){
            int pre = 0;
            for(int j = i; j < n;j++){
                pre += nums[j];
                sub.push_back(pre);
            }
        }
        sort(sub.begin(), sub.end());
        long res = 0;
        for(int i = left-1; i < right;i++) res = (res+sub[i])%mod;
        return res;
    }
};