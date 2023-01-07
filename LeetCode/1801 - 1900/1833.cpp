// 1833. Maximum Ice Cream Bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for(auto cost : costs){
            if(cost <= coins){
                coins -= cost;
                result++;
            }
            else break;
        }
        return result;
    }
};