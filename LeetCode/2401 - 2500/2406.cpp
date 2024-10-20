// 2406. Divide Intervals Into Minimum Number of Groups

// Solution 1 using Sorting and Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++) vec[i] = {intervals[i][0], intervals[i][1]};
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(vec[0].second);
        for(int i = 1; i < n;i++){
            if(vec[i].first > pq.top()){
                pq.pop();
                pq.push(vec[i].second);
            }
            else pq.push(vec[i].second);
        }
        return pq.size();
    }
};

// Solution 2 using Line Sweep Algorithm
// Line Sweep Algorithm is a general technique for solving interval problems.
// For each interval, we increment the value at the start point and decrement the value at the end point.
// This running total of all points shows how many intervals are active at any given point. The highest value of this total tells us the minimum number of groups needed to avoid overlap.
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto& interval: intervals){
            mp[interval[0]] += 1;
            mp[interval[1]+1] -= 1;
        }
        int res = 0, cnt = 0;
        for(auto& [_, val]: mp){
            cnt += val;
            res = max(res, cnt);
        }
        return res;
    }
};

// Solution 3 using Line Sweep Algorithm without map
// Time complexity: O(n + m)
// Space complexity: O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int start = INT_MAX, end = INT_MIN;
        for(auto& interval: intervals){
            start = min(start, interval[0]);
            end = max(end, interval[1]);
        }
        vector<int> vec(end+2, 0);
        for(auto& interval: intervals){
            vec[interval[0]] += 1;
            vec[interval[1]+1] -= 1;
        }
        int res = 0, cnt = 0;
        for(int i = start; i <= end;i++){
            cnt += vec[i];
            res = max(res, cnt);
        }
        return res;
    }
};
