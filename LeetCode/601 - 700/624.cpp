// 624. Maximum Distance in Arrays

// Solution 1: Brute Force by getting the maximum distance between apir by getting extremes from each array (Greedy)
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi = INT_MAX, mx = INT_MIN, res = 0;
        for(auto arr : arrays){
            if(mx != INT_MIN)
                res = max(res, mx - arr.front());
            if(mi != INT_MAX)
                res = max(res, arr.back() - mi);
            mi = min(arr.front(), mi);
            mx = max(arr.back(), mx);
        }
        return res;
    }
};

// Cleaner Solution 1 
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mi = arrays[0].front(), mx = arrays[0].back();
        for(int i = 1; i < arrays.size(); i++){
            res = max(res, max(abs(arrays[i].back() - mi), abs(mx - arrays[i].front())));
            mi = min(mi, arrays[i].front());
            mx = max(mx, arrays[i].back());
        }
        return res;
    }
};