// 2359. Find Closest Node to Given Two Nodes

class Solution {
public:
    void bfs(int node, vector<int>& edges, vector<int>& distance){
        queue<int> q;
        distance[node] = 0;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(edges[n] != -1 && distance[edges[n]] == INT_MAX){
                distance[edges[n]] = distance[n] + 1;
                q.push(edges[n]);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distance1(n,INT_MAX), distance2(n,INT_MAX);
        bfs(node1, edges,distance1);
        bfs(node2, edges,distance2);
        int m = 1e5 + 1;
        for(int i = 0; i < n;i++){
            m = min(m, max(distance1[i], distance2[i]));
        }
        if(m == 1e5+1) return -1;
        int i;
        for(i = 0; i < n;i++){
            if(m == max(distance1[i], distance2[i])){
                break;
            }
        }
        return i;
    }
};