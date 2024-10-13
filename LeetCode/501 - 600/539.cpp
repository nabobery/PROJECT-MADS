// 539. Minimum Time Difference

// Solution 1 using string manipulation and sorting (set)
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        set<int> s;
        int hours, minutes;
        char colon;
        for(string t : timePoints){
            istringstream timeStream(t);
            timeStream >> hours >> colon >> minutes;
            s.insert(hours*60 + minutes);
        }
        if(s.size() < timePoints.size()) return 0;
        vector<int> times(s.begin(), s.end());
        int res = 1440, n = times.size();
        for(int i = 0; i < n;i++){
            int diff = abs(times[(i+1) % n] - times[i]);
            diff = min(1440 - diff, diff);
            res = min(res, diff);
        }
        return res;
    }
};

// Solution 2 using bucket sort
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> bucket(1440, 0);
        for(string t : timePoints){
            int hours = stoi(t.substr(0, 2));
            int minutes = stoi(t.substr(3, 2));
            if(bucket[hours*60 + minutes] > 0) return 0;
            bucket[hours*60 + minutes]++;
        }
        int res = 1440, prev = -1, first = -1;
        for(int i = 0; i < 1440; i++){
            if(bucket[i] > 0){
                if(first == -1) first = i;
                if(prev != -1) res = min(res, i - prev);
                prev = i;
            }
        }
        return min(res, 1440 - prev + first);
    }
};