// 1011. Capacity To Ship Packages Within D Days

class Solution
{
public:
    bool isPossible(vector<int> &weights, int days, int weight)
    {
        int s = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > weight)
                return false;
            if (s + weights[i] > weight)
            {
                s = weights[i];
                days--;
            }
            else
                s += weights[i];
        }
        if (s <= weight)
            days--;
        return (days >= 0);
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 0, r = 3 * 1e7;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (!isPossible(weights, days, mid))
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l;
    }
};