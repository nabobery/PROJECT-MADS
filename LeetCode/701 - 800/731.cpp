// 731. My Calendar II

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// Solution 1 by maintaining two vectors of pairs
// One vector to store the intervals that are double booked (s2)
// Another vector to store the intervals that are atleast single booked (s1)
// Time complexity: O(n^2)
// Space complexity: O(n)
class MyCalendarTwo {
public:
    vector<pair<int,int>> s1, s2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& interval : s2) {
            if (interval.first < end && start < interval.second) {
                return false; 
            }
        }
        for (auto& interval : s1) {
            if (interval.first < end && start < interval.second) {
                s2.push_back({max(start, interval.first), min(end, interval.second)});
            }
        }
        s1.push_back({start, end});
        return true;
    }
};
