// 1436. Destination City

// Solution 1 simply return the city not having any outgoing path
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> visit;
        for(auto path : paths){
            visit.insert(path[0]);
        }
        for(auto path : paths){
            if(!visit.count(path[1]))
                return path[1];
        }
        return "";
    }
};

// Solution 2 Maintain a Adjacency List and check for the city not having any outgoing path
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> adj;
        for(auto path : paths){
            adj[path[0]] = path[1];
        }
        string res = paths[0][0];
        while(adj.count(res)){
            res = adj[res];
        }
        return res;
    }
};