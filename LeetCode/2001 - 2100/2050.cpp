// 2050. Parallel Courses III

// Solution 1 Topological Sort (Kahn's Algorithm)
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n, 0), maxTime(n, -1);
        int result = 0;
        for(auto relation : relations){
            graph[relation[0]-1].push_back(relation[1] - 1);
            indegree[relation[1] - 1]++;
        }
        queue<int> q;
        for(int i = 0; i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto i : graph[curr]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
                maxTime[i] = max(maxTime[i], maxTime[curr] + time[i]);
            }
        }
        for(auto i : maxTime) result = max(i, result);
        return result;
    }
};

// Solution 2 using DFS + Memoization
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<int> dp;
    int dfs(int curr, vector<int>& time){
        if(dp[curr] != -1) return dp[curr];
        int result = 0;
        if(graph[curr].size() == 0) return time[curr];
        for(auto i : graph[curr]){
            result = max(result, dfs(i, time));
        }
        return dp[curr] = result + time[curr];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        dp.resize(n, -1);
        for(auto relation : relations){
            graph[relation[0]-1].push_back(relation[1] - 1);
        }
        int result = 0;
        for(int i = 0; i < n;i++){
            result = max(result, dfs(i, time));
        }
        return result;
    }
};


