// 746. Min Cost Climbing Stairs

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int t0 = cost[0], t1 = cost[1], temp;
        for (int i = 2; i <= n; i++)
        {
            temp = t1;
            t1 = (i < n ? cost[i] : 0) + min(t0, t1);
            t0 = temp;
        }
        return t1;
    }
};