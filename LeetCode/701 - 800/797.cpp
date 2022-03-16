// 797. All Paths From Source to Target
// Using DFS
class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<vector<int>>& graph, int u, vector <int> path){
        path.push_back(u);
        if(u == size(graph) - 1){
            result.push_back(path);
        }
        else {
            for(auto node : graph[u]){
                dfs(graph, node, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return result;
    }
};