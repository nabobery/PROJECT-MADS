// 1235. Maximum Profit in Job Scheduling

// Solution 1 - Top Down DP + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<int,int> dp;
    struct job{
        int start, end, profit;
    };
    static bool comp(job const& a, int const i){
        return a.start < i;
    }
    static bool comparator(job& a, job& b){
        return a.start < b.start;
    }
    int helper(int i, vector<job>& jobs){
        if(i >= jobs.size()) return 0;
        if(dp.count(i)) return dp[i];
        int res = helper(i+1, jobs);
        auto it = lower_bound(jobs.begin(), jobs.end(), jobs[i].end, comp) - jobs.begin();
        res = max(res, jobs[i].profit + helper(it, jobs));
        return dp[i] = res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), res = 0;
        vector<job> jobs(n);
        for(int i = 0; i < n;i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), comparator);
        return helper(0, jobs);
    }
};

// A better and faster Solution 1
class Solution {
public:
    struct job{
        int start, end, profit;
    };
    static bool comp(job const& a, int const i){
        return a.start < i;
    }
    static bool comparator(job& a, job& b){
        return a.start < b.start;
    }
    int helper(int i, vector<job>& jobs, vector<int>& dp){
        if(i >= jobs.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = helper(i+1, jobs,dp);
        auto it = lower_bound(jobs.begin(), jobs.end(), jobs[i].end, comp) - jobs.begin();
        res = max(res, jobs[i].profit + helper(it, jobs,dp));
        return dp[i] = res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), res = 0;
        vector<job> jobs(n);
        for(int i = 0; i < n;i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), comparator);
        vector<int> dp(n, -1);
        return helper(0, jobs,dp);
    }
};

// Solution 2 - Bottom Up DP + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    struct job{
        int start, end, profit;
    };
    static bool comp(job const& a, int const i){
        return a.start < i;
    }
    static bool comparator(job& a, job& b){
        return a.start < b.start;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), res = 0;
        vector<job> jobs(n);
        for(int i = 0; i < n;i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), comparator);
        vector<int> dp(n, 0);
        dp[n-1] = jobs[n-1].profit;
        for(int i = n-2; i >= 0; i--){
            dp[i] = max(dp[i+1], jobs[i].profit);
            auto it = lower_bound(jobs.begin(), jobs.end(), jobs[i].end, comp) - jobs.begin();
            if(it < n) dp[i] = max(dp[i], jobs[i].profit + dp[it]);
        }
        return dp[0];
    }
};