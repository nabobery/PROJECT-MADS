// 1353. Maximum Number of Events That Can Be Attended

// Solution 1 using Greedy + Min-Heap
// Time Complexity: O(n log n), where n is the number of events
// Space Complexity: O(n), for the priority queue
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int res = 0, mx  = 0, start = 0, n = events.size();
        for(int i = 0; i < n;i++) mx = max(mx, events[i][1]);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i <= mx;i++){
            while(start < n && events[start][0] <= i) pq.push(events[start++][1]);
            while(!pq.empty() && pq.top() < i) pq.pop();
            if(!pq.empty()){
                res++;
                pq.pop();
            }
        }
        return res;
    }
};