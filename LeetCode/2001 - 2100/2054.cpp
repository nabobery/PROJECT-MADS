// 2054. Two Best Non-Overlapping Events

// Solution 1 using Sorting, Binary Search and Top Down Dynamic Programming
// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // sort by start
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        // 0-1 DP where dp[i][j] is the maximum profit for i events where ith event is included or not
        vector<vector<int>> dp(events.size(), vector<int>(2, -1));
        // start from the first event
        return findEvents(events, 0, 0, dp);
    }

private:
    int findEvents(vector<vector<int>>& events, int idx, int cnt, vector<vector<int>>& dp) {
        // base case
        if (cnt == 2 || idx >= events.size()) return 0;
        // memoization
        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        // recursive case
        // binary search for next element that can be included if we include the current event
        int end = events[idx][1];
        int lo = idx + 1, hi = events.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > end)
                hi = mid;
            else
                lo = mid + 1;
        }

        // include the current event
        int include = events[idx][2] + (lo < events.size() ? findEvents(events, lo, cnt + 1, dp) : 0);
        // exclude the current event
        int exclude = findEvents(events, idx + 1, cnt, dp);
        // get maximum sum of inlude and exclude cases
        dp[idx][cnt] = max(include, exclude);
        return dp[idx][cnt];
    }
};

// Solution 2 using Min Heap
// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // min heap to store end time and profit
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // sort by start
        sort(events.begin(), events.end());
        int res = 0, mx = 0;
        // for each event
        for(auto& event : events) {
            // pop all end times that are less than start time
            while(!pq.empty() && pq.top().first < event[0]){
                mx = max(mx, pq.top().second);
                pq.pop();
            }
            // see what happens if we can include the current event and any events before it or exclude it
            res = max(res, mx + event[2]);
            // push end time and profit
            pq.push({event[1], event[2]});
            
        }
        return res;
    }
};
       