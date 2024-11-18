// 862. Shortest Subarray with Sum at Least K

// Solution 1: Using Prefix Sum TLE
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n+1;
        if(n == 1) return (nums[0] >= k) ? 1 : -1;
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n;i++) prefix[i+1] += (prefix[i] + nums[i]);
        for(int l = 0; l < n;l++){
            for(int r = l; r < n;r++){
                long sum = prefix[r+1];
                sum -= prefix[l];
                if(sum >= k) res = min(res, r-l+1);
            }
        }
        return (res == n+1) ? -1 : res;
    }
};

// Solution 2: Using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n+1;
        if(n == 1) return (nums[0] >= k) ? 1 : -1;
        long sum = 0;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, -1});
        for(int i = 0; i < n;i++){
            sum += nums[i];
            while(!pq.empty() && sum - pq.top().first >= k){
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return (res == n+1) ? -1 : res;
    }
};


// Solution 3: Using Deque
// Time complexity: O(n)
// Space complexity: O(n)
// The idea is to not consider negative values in the prefix sum array.
// If the prefix sum array is increasing, we can use a deque to store the indices and see if the sum is greater than k by removing the indices from the front of the deque.
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n+1;
        if(n == 1) return (nums[0] >= k) ? 1 : -1;
        vector<long> prefix(n+1, 0);
        for(int i = 0; i < n;i++) prefix[i+1] += (prefix[i] + nums[i]);
        deque<int> dq;
        for(int i = 0; i <= n;i++){
            // if the prefix sum is greater than k, we can remove the indices from the front of the deque until the sum is less than k to get 
            // the shortest subarray
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            // if the prefix sum is decreasing, we can remove the indices from the back of the deque to maintain the increasing order
            while(!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
            // add the index to the deque
            dq.push_back(i);
        }
        return (res == n+1) ? -1 : res;
    }
};