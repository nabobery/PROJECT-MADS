// 1743. Restore the Array From Adjacent Pairs

// Solution 1 using Hashmap and some kind Iterative Traversal
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        for(auto it : adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it : adj){
            if(it.second.size() == 1){
                res.push_back(it.first);
                break;
            }
        }
        while(adj.size() > 1){
            int temp = res.back();
            for(auto it : adj[res.back()]){
                if(adj.count(it)){
                    res.push_back(it);
                }
            }
            adj.erase(temp);
        }
        return res;
    }
};

// Solution 2 using Hashmap and some kind of Recursive Traversal
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        for(auto it : adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it : adj){
            if(it.second.size() == 1){
                res.push_back(it.first);
                break;
            }
        }
        dfs(adj, res, res.back());
        return res;
    }
    void dfs(unordered_map<int, vector<int>>& adj, vector<int>& res, int temp){
        if(adj.size() == 1){
            return;
        }
        for(auto it : adj[temp]){
            if(adj.count(it)){
                res.push_back(it);
                adj[it].erase(find(adj[it].begin(), adj[it].end(), temp));
                adj.erase(temp);
                dfs(adj, res, it);
                break;
            }
        }
    }
};

