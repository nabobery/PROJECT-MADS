// 3347. Maximum Frequency of an Element After Performing Operations II

// Solution using a sweep line algorithm with event sorting.
// Time Complexity: O(n log n) due to sorting the events.
// Space Complexity: O(n) for storing the events.
// The idea is 
// find a target value T that maximizes this function: f(T) = exactCount(T) + min(availableCount(T), numOperations)
// Instead of checking every possible integer T, we can imagine a "line" (our target value) sweeping from negative infinity to positive infinity. The values of totalCount and exactCount only change when T hits specific "event" coordinates.
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // We no longer need to sort nums, though it doesn't hurt.
        // The event sorting is what matters.
        
        // vector<pair<coordinate, type>>
        // type 0: START_TOTAL (num - k)
        // type 1: START_EXACT (num)
        // type 2: END_EXACT   (num + 1)
        // type 3: END_TOTAL   (num + k + 1)
        vector<pair<int, int>> events;
        
        for (int num : nums) {
            events.push_back({num - k, 0});
            events.push_back({num, 1});
            events.push_back({num + 1, 2});
            events.push_back({num + k + 1, 3});
        }
        
        // Sort the events. The default pair sort works perfectly:
        // 1. Sorts by `first` (coordinate)
        // 2. If `first` is equal, sorts by `second` (type)
        sort(events.begin(), events.end());
        
        int maxFreq = 0;
        int totalCount = 0;
        int exactCount = 0;
        
        int i = 0;
        int n = events.size();
        
        while (i < n) {
            int currentCoord = events[i].first;
            
            // Process all events at this same coordinate
            while (i < n && events[i].first == currentCoord) {
                int type = events[i].second;
                if (type == 0) { // START_TOTAL
                    totalCount++;
                } else if (type == 1) { // START_EXACT
                    exactCount++;
                } else if (type == 2) { // END_EXACT
                    exactCount--;
                } else { // type == 3, END_TOTAL
                    totalCount--;
                }
                i++;
            }
            
            // Now that the state is updated, calculate the frequency
            // for the interval [currentCoord, nextCoord)
            int availableCount = totalCount - exactCount;
            int currentFreq = exactCount + min(availableCount, numOperations);
            maxFreq = max(maxFreq, currentFreq);
        }
        
        return maxFreq;
    }
};