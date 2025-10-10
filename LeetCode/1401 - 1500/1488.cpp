// 1488. Avoid Flood in The City

// Solution 1: Greedy Approach Using Last Occurrence Tracking and Set and Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> lastRained;
        set<int> dryLakeDays;
        for(int i = 0; i < n;i++){
            int lake = rains[i];
            if(lake){
                if(lastRained.count(lake)){
                    if(dryLakeDays.empty()) return {};
                    else{
                        auto it = dryLakeDays.upper_bound(lastRained[lake]);
                        if(it == dryLakeDays.end()) return {};
                        res[*it] = lake;
                        dryLakeDays.erase(it);
                    }
                }
                lastRained[lake] = i;
                res[i] = -1;
            }
            else dryLakeDays.insert(i);
        }
        return res;
    }
};