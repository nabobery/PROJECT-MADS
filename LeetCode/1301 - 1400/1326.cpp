// 1326. Minimum Number of Taps to Open to Water a Garden

// Solution: Greedy using Sorting 
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // get the intervals
        vector<pair<int,int>> interval(n+1);
        for(int i = 0; i <= n;i++){
            // if a tap can cover the whole garden [0, n] return 1
            if(i-ranges[i] <= 0 && i+ranges[i] >= n) return 1;
            interval[i] = {i - ranges[i], i + ranges[i]};
        }
        // sort the intervals
        sort(interval.begin(), interval.end()); 
        // start from the first interval
        pair<int,int> p = interval[0];
        // initialize the result and the previous reach
        int result = 1, prevReach = p.second;
        // iterate through the intervals
        for(int i = 1; i <= n;i++){
            // if the current interval is out of reach (there's a gap between taps) return -1
            if(p.second < interval[i].first) return -1;
            // if the current interval's reach is less than the previous one, skip
            if(interval[i].second <= p.second) continue;
            // if the current interval as same starting point as the previous one or it starts < 0 
            // because we are having a greater reach, we can skip the previous interval
            if((p.first == interval[i].first) || (interval[i].first <= 0)){
                p = interval[i];
                prevReach = p.second;
            } 
            // else
            else{
                // if the current interval's starting point is greater than the previous reach
                if(prevReach < interval[i].first){
                    // we need to add a new tap
                    prevReach = p.second;
                    result++;
                }
                // update the previous reach
                p.second = interval[i].second;
            }
            // if we can reach the end of the garden, break
            if(p.second >= n) break;
        }
        // return the result + 1 because we didn't count the last tap when we break
        return result+1;
    }
};


// Solution: using DP
// Time complexity: O(nm)
// Space complexity: O(n)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // dp[i] = minimum number of taps to water [0, i]
        vector<int> dp(n+1, n+2);
        // dp[0] = 0 because we don't need any tap to water [0, 0]
        dp[0] = 0;
        // iterate through the taps
        for(int i = 0; i <= n;i++){
            // find the left and right end of the current tap 
            int leftEnd = max(0, i-ranges[i]), rightEnd = min(n, i+ranges[i]);
            // iterate through the range of the current tap
            for(int j = leftEnd; j <= rightEnd;j++) 
                // update the minimum number of taps to water [0, rightEnd] by using the current tap and taps from dp[0,j]
                dp[rightEnd] = min(dp[rightEnd], dp[j] + 1);
        }
        // if we can't water the whole garden from [0,n] return -1
        if(dp[n] == n+2)
            return -1;
        // return dp[n]
        return dp[n];    
    }
};

// Solution: using Greedy Strategy
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // maxReach[i] = maximum reach starting from location i
        vector<int> maxReach(n+1, 0);
        for(int i = 0; i <= n;i++){
            int leftEnd = max(0, i-ranges[i]), rightEnd = min(n, i+ranges[i]);
            // get the maximum reach starting from location leftEnd
            maxReach[leftEnd] = max(maxReach[leftEnd], rightEnd);
        }
        int res = 0, curr = 0, next = 0;
        for(int i = 0; i <= n;i++){
            // if we can't reach location i return -1
            if(i > next) return -1;
            // if we need a new tap to reach location i
            if(i > curr){
                res++;
                curr = next;
            }
            // update the next reach
            next = max(next, maxReach[i]);
        }
        return res;
    }
};
