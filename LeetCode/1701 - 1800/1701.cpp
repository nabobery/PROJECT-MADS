// 1701. Average Waiting Time

// Solution 1: Simple and Straightforward Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), ct = 0;
        double res = 0;
        for(int i = 0; i < n;i++){
            if(ct < customers[i][0]) ct = customers[i][0];
            ct += customers[i][1];
            res += (ct - customers[i][0]);
        }
        res /= n;
        return res;
    }
};