// 1425. Constrained Subsequence Sum


// Solution 1 using dp and multiset
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), res = nums[0];
        // dp[i] is the max constrained subset sum ending at i, if we choose nums[i]
        vector<int> dp(n, -1e4);
        dp[0] = nums[0];
        // multiset is used to find the max value in the sliding window
        multiset<int> s;
        s.insert(dp[0]);
        for(int i = 1; i < n;i++){
            // dp[i] is the max value in the sliding window + nums[i]
            // if the max value in the sliding window is negative, we don't add it to dp[i] and we just use nums[i]
            dp[i] = nums[i] + max(0,*s.rbegin());
            // if the size of the sliding window is greater than k, we need to remove the first element of the window
            if(s.size() >= k) s.erase(s.find(dp[i-k]));
            // insert the current dp[i] into the sliding window
            s.insert(dp[i]);
            // update the result
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Solution 2 using dp and priority queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size(), res = nums[0];
        pq.push({nums[0], 0});
        for(int i = 1; i < n;i++){
            // we pop the first element of the priority queue if it is out of the sliding window
            while(!pq.empty() && pq.top().second < i - k) pq.pop();
            // dp[i] is the max value in the sliding window + nums[i]
            // if the max value in the sliding window is negative, we don't add it to dp[i] and we just use nums[i]
            int dp = nums[i] + max(0, pq.top().first);
            // insert the current dp[i] into the sliding window
            pq.push({dp, i});
            // update the result
            res = max(res, dp);
        }
        return res;
    }
};

// Solution 3 using dp and map
// Time complexity: O(nlogk)
// Space complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size();i++){
            dp[i] = nums[i] + mp.rbegin()->first;
            mp[dp[i]] = i;
            if(i >= k){
                mp[dp[i-k]]--;
                if(mp[dp[i-k]] == 0) mp.erase(dp[i-k]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// Solution 4 using dp and deque
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // deque is used to find the max value in the sliding window
        deque<int> dq;
        // dp[i] is the max constrained subset sum ending at i, if we choose nums[i]
        vector<int> dp(nums.size());
        for(int i = 0; i < nums.size();i++){
            // we pop the first element of the deque if it is out of the sliding window
            if(!dq.empty() && dq.front() < i - k) dq.pop_front();
            // dp[i] is the max value in the sliding window + nums[i]
            dp[i] = nums[i] + max(0, dq.empty() ? 0 : dp[dq.front()]);
            // Monotonic increasing deque so we pop the last element if it is smaller than dp[i]
            while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
            // insert the current dp[i] into the sliding window
            if(dp[i] > 0) dq.push_back(i);
        }
        // return the max value in dp
        return *max_element(dp.begin(), dp.end());
    }
};
