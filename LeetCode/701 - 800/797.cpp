// 797. All Paths From Source to Target

// Solution 1 using dfs
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> result;
    void dfs(int u, vector<vector<int>>& graph, vector <int> path){
        path.push_back(u);
        if(u == graph.size() - 1)
            result.push_back(path);
        else {
            for(auto node : graph[u])
                dfs(node, graph, path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, graph, path);
        return result;
    }
};

// Solution 2 using bfs
// Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            vector<int> path = q.front();
            q.pop();
            int u = path.back();
            if(u == graph.size() - 1)
                result.push_back(path);
            else {
                for(auto node : graph[u]){
                    vector<int> newPath = path;
                    newPath.push_back(node);
                    q.push(newPath);
                }
            }
        }
        return result;
    }
};