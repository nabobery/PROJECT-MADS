// 3264. Final Array State After K Multiplication Operations I

// Solution 1: Using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(n);
        for(int i = 0; i < n;i++) pq.push({nums[i], i});
        while(k--){
            auto it = pq.top();
            pq.pop();
            pq.push({it.first*multiplier, it.second});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            res[it.second] = it.first;
        }
        return res;
    }
};