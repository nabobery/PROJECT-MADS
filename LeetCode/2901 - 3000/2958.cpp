// 2958. Length of Longest Subarray With at Most K Frequency

// Solution 1 using Two Pointers and Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
// The idea is to maintain a window [l, r] such that the frequency of each element in the window is at most k.
// We can use a hashmap to store the frequency of each element in the window.
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0, l = -1;
        unordered_map<int, int> mp;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                l++;
                mp[nums[l]]--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};


// Solution 2 using Two Pointers and Sliding Window without nested while loop and moving the left pointer one by one
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, cnt = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            if(mp[nums[r]] == k+1) cnt++;
            if(cnt > 0){
                mp[nums[l]]--;
                if(mp[nums[l]] == k) cnt--;
                l++;
            }
        }
        return n-l;
    }
};