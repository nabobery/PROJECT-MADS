// 1462. Course Schedule IV

//  Solution 1 using Bruteforce (TLE)
//  Time Complexity: O(n^2*q)
//  Space Complexity: O(n^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res(n, false);
        vector<vector<int>> adj(numCourses);
        // vector<int> indegree(numCourses, 0);
        for(auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            // indegree[edge[0]]++;
        }
        for(int i = 0; i < n;i++){
            int dest = queries[i][0], src = queries[i][1];
            queue<int> q;
            q.push(src);
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                if(curr == dest){
                    res[i] = true;
                    break;
                }
                for(auto next: adj[curr]) q.push(next);
            }
        }
        return res;
    }
};

// Solution 2 using reachable matrix to see if a course is a prerequisite of another course
// Time Complexity: O(n^2 + q)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; i++) {
            reachable[i][i] = true;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                for (int w = 0; w < numCourses; w++) {
                    if (reachable[w][u]) {
                        reachable[w][v] = true;
                    }
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<bool> res;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            res.push_back(reachable[u][v]);
        }

        return res;
    }
};

