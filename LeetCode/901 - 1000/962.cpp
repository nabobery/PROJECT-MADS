// 962. Maximum Width Ramp

// Solution 1: Using sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
// The idea is to sort the array and then find the maximum difference between the index of the elements
// by maintaining the minimum index of the elements seen so far.
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0, n = nums.size(), mi = n;
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {nums[i], i};
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n;i++){
            if(mi == -1) mi = vec[i].second;
            else{
                mi = min(mi, vec[i].second);
                res = max(res, vec[i].second - mi);
            }
        }
        return res;
    }
};

// Solution 2: Using Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)
// The idea is to use a monotonic stack to find the maximum difference between the index of the elements
// by maintaining the minimum index of the elements seen so far.
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0, n = nums.size();
        stack<int> st;
        for(int i = 0; i < n;i++) if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        for(int i = n-1; i >= 0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};