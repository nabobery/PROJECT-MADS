// 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // sorting based on start time
        int index = 0;
        for(int i = 1; i < n;i++){
            if(intervals[index][1] >= intervals[i][0]){
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else{
                index++;
                intervals[index] = intervals[i];
            }
        }
        // remove the extra intervals
        for(int i = 1; i < n - index;i++){
            intervals.pop_back();
        }
        return intervals;
    }
};