// 435. Non-overlapping Intervals
// O(nlogn) time Greedy solution
class Solution {
public:
    // comparison of sorting based on end
    static bool comp(const vector<int> &a, const vector<int> &b){
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int result = 0, prev = intervals[0][1];
        for(int i = 1; i < n;i++){
            if(prev > intervals[i][0]) result++;
            else prev = intervals[i][1];
        }
        return result;
    }
};
/*We traverse the array and check if there's any prev end which is greater than the next start which means the intervals containing start
 * has more width which means it's overlapping so we do result++ else we take the next element as start. As we use sort to get
 * earliest end time it's a greedy strategy.
 */

