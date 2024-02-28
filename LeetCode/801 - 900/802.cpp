// 802. Find Eventual Safe States

// Solution 1 using BruteForce every path using DFS - TLE
// Time complexity: O(V+E)
// Space complexity: O(V+E)
class Solution {
public:
    bool isSafe(int u, vector<vector<int>>& graph, bool visited[]){
        if(visited[u]) return false;
        visited[u] = true;
        bool b = true;
        for(int v : graph[u])
            b &= isSafe(v, graph, visited);
        visited[u] = false;
        return b;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n;i++)
            if(isSafe(i, graph, visited)) res.push_back(i);
        return res;
    }
};

// Solution 2 using DFS with memoization
// Time complexity: O(V+E)
// Space complexity: O(V+E)
// state[u] = 0: not visited
// state[u] = 1: safe
// state[u] = 2: unsafe
class Solution {
public:
    bool isSafe(int u, vector<vector<int>>& graph, int state[]){
        if(state[u] != 0) return state[u] == 1;
        state[u] = 2;
        for(int v : graph[u])
            if(!isSafe(v, graph, state)) return false;
        state[u] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        int state[n];
        memset(state, 0, sizeof(state));
        for(int i = 0; i < n;i++)
            if(isSafe(i, graph, state)) res.push_back(i);
        return res;
    }
};

// Solution 3 using Topological Sort
// Time complexity: O(V+E)
// Space complexity: O(V+E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res, outdegree(n, 0);
        vector<vector<int>> reverseGraph(n);
        for(int i = 0; i < n;i++)
            for(int j : graph[i]){
                reverseGraph[j].push_back(i);
                outdegree[i]++;
            }
        queue<int> q;
        for(int i = 0; i < n;i++)
            if(outdegree[i] == 0) q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int v : reverseGraph[u])
                if(--outdegree[v] == 0) q.push(v);
        }
        sort(res.begin(), res.end());
        return res;
    }
};