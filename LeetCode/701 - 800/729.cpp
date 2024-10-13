// 729. My Calendar I

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// Solution 1 using set of pairs
// Time complexity: O(nlogn)
// Space complexity: O(n)
class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
    
    }
    
    bool book(int start, int end) {
        if(s.empty()){
            s.insert({start, end});
            return true;
        }
        auto upper = s.upper_bound({start, end});
        auto lower = upper; lower--;
        if(upper != lower && (lower->second > start || (upper != s.end() && end > upper->first))) return false;
        if(upper == lower && upper->first < end) return false;
        s.insert({start, end});
        return true;
    }
};

// Solution 2 using vector of pairs
// Time complexity: O(n^2)
// Space complexity: O(n)
class MyCalendar {
public:
    vector<pair<int,int>> s;
    MyCalendar() {
    
    }
    
    bool book(int start, int end) {
        for(auto& interval : s){
            if(interval.first < end && start < interval.second) return false;
        }
        s.push_back({start, end});
        return true;
    }
};

