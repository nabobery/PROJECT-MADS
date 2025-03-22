// 2115. Find All Possible Recipes from Given Supplies

// Solution 1: Topological Sort
// Time complexity: O(N + E)
// Space complexity: O(N + E)
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            vector<string> res;
            unordered_map<string, int> nodes;
            int n = recipes.size(), p = n;
            unordered_map<int,int> indegree; // for recipe nodes
            unordered_map<int, vector<int>> adj;
            for(int i = 0; i < n;i++) nodes[recipes[i]] = i;
            // build graph and get indegree of all recipe nodes
            for(int i = 0; i < n;i++){
                for(string ingredient : ingredients[i]){
                    if(!nodes.count(ingredient))
                        nodes[ingredient] = p++; 
                    adj[nodes[ingredient]].push_back(i);
                }
                indegree[i] = ingredients[i].size();
            } 
            // push all supplies to queue
            queue<int> q;
            for(string supply : supplies)
                if(nodes.count(supply)) q.push(nodes[supply]);
            // do topological sort and check if any recipe node has indegree 0
            // if yes, add it to result
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                for(auto node : adj[curr]){
                    if(indegree.count(node)){
                        indegree[node]--;
                        if(indegree[node] == 0) q.push(node);
                    }
                }
            }
            for(auto it : indegree){
                if(it.second == 0){
                    res.push_back(recipes[it.first]);
                }
            }
            return res;
        }
};