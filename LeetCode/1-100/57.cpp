// 57. Insert Interval

// Solution 1 using Sorting and then merging intervals
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int index = 0, n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (intervals[index][1] >= intervals[i][0])
            {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else
            {
                index++;
                intervals[index] = intervals[i];
            }
        }
        for (int i = 1; i < n - index; i++)
        {
            intervals.pop_back();
        }
        return intervals;
    }
};

// Solution 2 using Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i++]);
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while (i < n)
        {
            result.push_back(intervals[i++]);
        }
        return result;
    }
};