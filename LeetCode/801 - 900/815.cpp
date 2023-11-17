// 815. Bus Routes

// Solution 1 BFS using Bus routes as nodes
// Time complexity: O(N^2*K)
// Space complexity: O(N^2)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        vector<unordered_set<int>> vec(n);
        for(int i = 0; i < n;i++){
            vec[i] = unordered_set<int>(routes[i].begin(), routes[i].end());
        }
        vector<vector<int>> adj(n);
        unordered_set<int> sources, visited;
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n;j++){
                for(auto it : vec[i]){
                    if(vec[j].count(it)){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n;i++){
            if(vec[i].count(source)) sources.insert(i);
        }
        queue<int> q;
        for(auto it : sources){
            q.push(it);
            visited.insert(it);
        }
        int bus = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(vec[curr].count(target)) return bus;
                for(auto it : adj[curr]){
                    if(!visited.count(it)){
                        visited.insert(it);
                        q.push(it);
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};

// Solution 2 BFS using Bus stops as nodes
// Time complexity: O(N^2*K)
// Space complexity: O(N*K)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n;i++){
            for(auto it : routes[i]){
                mp[it].push_back(i);
            }
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        int bus = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(curr == target) return bus;
                for(auto it : mp[curr]){
                    if(!visited[it]){
                        visited[it] = true;
                        for(auto it2 : routes[it]){
                            q.push(it2);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};