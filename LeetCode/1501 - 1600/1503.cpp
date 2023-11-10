// 1503. Last Moment Before All Ants Fall Out of a Plank

// Solution 1 using Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// n = length of plank
// left = vector of ants that are initially moving to the left
// right = vector of ants that are initially moving to the right
// The logic is that the ants that are moving to the left will take n - left[i] seconds to fall off the plank, 
// and the ants that are moving to the right will take right[i] seconds to fall off the plank. 
// Therefore, the last moment before all ants fall off the plank is the maximum of the two.

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto l : left) res = max(res, l);
        for(auto r : right) res = max(res, n-r);
        return res;
    }
};