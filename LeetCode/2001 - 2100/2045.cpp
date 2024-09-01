// 2045. Second Minimum Time to Reach Destination

// Solution 1: Using BFS by maintaining 2 distance vectors (one for minimum and another for 2nd minimum)
// Time complexity: O(V+E)
// Space complexity: O(V+E)
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // build adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int, int>> q;
        // dist1 stores the minimum time to reach node i
        // dist2 stores the 2nd minimum time to reach node i
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        // push the source node and turn (1st or 2nd) into the queue
        q.push({1, 1});
        //  time to reach source node is 0
        dist1[1] = 0;
        // run the BFS from source node
        while(!q.empty()){
            auto [u, turn] = q.front();
            q.pop();
            // keep track of the current time to reach node u based on the turn
            int curr_time = turn == 1 ? dist1[u] : dist2[u];
            // if the current time is not a multiple of change, then add the time to reach the node (green -> red and red-> green)
            //  add change time + time to go from node u to node v
            if(curr_time/change % 2) curr_time += change*(curr_time/change + 1) + time;
            // else just add the time to go from node u to node v
            else curr_time += time;
            // if the node is 1st time visited, then update the time to reach the node and push it into the queue
            if(dist1[v] == -1){
                dist1[v] = curr_time;
                q.push({v, 1});
            }
            // if the node is 2nd time visited, then update the time to reach the node and push it into the queue
            else if(dist2[v] == -1 && dist1[v] != curr_time){
                dist2[v] = curr_time;
                q.push({v,2});
            }
        }
        // return the 2nd minimum time to reach the destination node
        return dist2[n];
    }
};

