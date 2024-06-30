// 826. Most Profit Assigning Work

// Solution 1 using Greedy Approach using Sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, n = profit.size(), p = 0, mx = 0;
        sort(worker.begin(), worker.end());
        vector<pair<int,int>> diffprofit(n);
        for(int i = 0; i < n;i++) diffprofit[i] = {difficulty[i], profit[i]};
        sort(diffprofit.begin(), diffprofit.end());
        for(int w : worker){
            while(p < n && diffprofit[p].first <= w){
                mx = max(mx, diffprofit[p].second);
                p++;
            }
            res += mx;
        }
        return res;
    }
};

// Solution 2 using Greedy Approach using Binary Search
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, n = profit.size(), mx = 0;
        vector<pair<int,int>> diffprofit(n);
        for(int i = 0; i < n;i++) diffprofit[i] = {difficulty[i], profit[i]};
        sort(diffprofit.begin(), diffprofit.end());
        for(int i = 1; i < n; i++) diffprofit[i].second = max(diffprofit[i].second, diffprofit[i-1].second);
        for(int w : worker){
            auto it = upper_bound(diffprofit.begin(), diffprofit.end(), make_pair(w, INT_MAX));
            if(it != diffprofit.begin()) res += prev(it)->second;
        }
        return res;
    }
};