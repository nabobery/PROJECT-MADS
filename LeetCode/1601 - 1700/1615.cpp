// 1615. Maximal Network Rank

// Solution 1 by maintaing a vector of hashmaps as adj
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        for(auto road : roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        int res = 0;
        for(int i = 0; i < n-1;i++){
            for(int j =i+1; j < n;j++){
                int curr = adj[i].size() + adj[j].size();
                if(adj[i].count(j)) curr--;
                res = max(res, curr);
            }
        }
        return res;
    }
};

