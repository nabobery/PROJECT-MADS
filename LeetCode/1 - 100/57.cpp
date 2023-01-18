// 57. Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int index = 0, n = intervals.size();
        for(int i = 1; i < n;i++){
            if(intervals[index][1] >= intervals[i][0]){
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else{
                index++;
                intervals[index] = intervals[i];
            }
        }
        for(int i = 1; i < n - index;i++){
            intervals.pop_back();
        }
        return intervals;
    }
};