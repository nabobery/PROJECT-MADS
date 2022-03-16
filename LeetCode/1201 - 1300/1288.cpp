// 1288. Remove Covered Intervals
// sort based on ascending order of start, if start is equal, then sort based on descending order of end
// if end <= next end it means next covers prev intervals
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        int result = 0, end = intervals[0][1], n = intervals.size();
        for(int i = 1; i < n;i++){
            if(intervals[i][1] <= end) result++;
            end = max(end, intervals[i][1]);
        }
        return (n - result);
    }
};

// sort based on start
// if we find an interval > start and greater than end it means it covers other intervals till now so result++
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int result= 0, start = -1, end = -1;
        for(vector<int> v : intervals){
            if(v[0] > start && v[1] > end){
                start = v[0];
                result++;
            }
            end = max(end,v[1]);
        }
        return result;
    }
};
