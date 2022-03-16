// 1672. Richest Customer Wealth
// my naive solution
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(vector<int>&v : accounts){
            int curr = 0;
            for(int wealth : v){
                curr += wealth;
            }
            if(curr > max){
                max = curr;
            }
        }
        return max;
    }
};



