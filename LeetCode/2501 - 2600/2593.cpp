// 2593. Find Score of an Array After Marking All Elements

// Solution 1: Using Priority Queue and visited array
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        long long res = 0;
        for(int i = 0; i < n;i++) pq.push({nums[i], i});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(!visited[it.second]){
                visited[it.second] = true;
                if(it.second < n-1)  visited[it.second+1] = true;
                if(it.second > 0)  visited[it.second-1] = true;
                res += it.first;
            }
        }
        return res;
    }
};